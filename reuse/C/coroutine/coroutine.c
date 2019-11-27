/* =============================================================================
> File Name: coroutine.c
> Author: DaiDai
> Mail: daidai4269@aliyun.com
> Created Time: Thu 21 Nov 2019 05:38:01 PM CST
============================================================================= */


#include "coroutine.h"

#include <stddef.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdint.h>

#if __APPLE__ && __MACH__
#include <sys/ucontext.h>
#else
#include <ucontext.h>
#endif


#define STACK_SIZE (1024 * 1024) // 1MB
#define DEFAULT_COROUTINE_NUM 16


struct Coroutine;

struct Schedule {
  char stack[STACK_SIZE];
  ucontext_t context;
  int num_co;
  int capacity;
  int running_id;
  struct Coroutine** co;
};

struct Coroutine {
  coroutine_func func;
  void* ud;
  ucontext_t context;
  struct Schedule* sch;
  ptrdiff_t capacity;
  ptrdiff_t size;
  int status;
  char* stack;
};

struct Coroutine* _co_new(struct Schedule* S, coroutine_func func, void* ud) {
  struct Coroutine* co = malloc(sizeof(* S));
  co->func = func;
  co->ud = ud;
  co->sch = S;
  co->capacity = 0;
  co->size = 0;
  co->status = COROUTINE_STATUS_READY;
  co->stack = NULL;
  return co;
}

void _co_delete(struct Coroutine* co) {
  free(co->stack);
  free(co);
}

struct Schedule* coroutine_open(void) {
  struct Schedule* S = malloc(sizeof(* S));
  S->num_co = 0;
  S->capacity = DEFAULT_COROUTINE_NUM;
  S->running_id = -1;
  S->co = malloc(sizeof(struct Coroutine* ) * S->capacity);
  memset(S->co, 0, sizeof(struct Coroutine* ) * S->capacity);
  return S;
}

void coroutine_close(struct Schedule* S) {
  for (int i = 0; i < S->capacity; ++i) {
    struct Coroutine* co = S->co[i];
    if (co)
      _co_delete(co);
  }

  free(S->co);
  S->co = NULL;
  free(S);
}

int coroutine_new(struct Schedule* S, coroutine_func func, void* ud) {
  struct Coroutine* co = _co_new(S, func, ud);
  if (S->num_co >= S->capacity) {
    int id = S->capacity;
    S->co = realloc(S->co, S->capacity * 2 * sizeof(struct Coroutine* ));
    memset(S->co + S->capacity, 0, sizeof(struct Coroutine* ) * S->capacity);
    S->co[S->capacity] = co;
    S->capacity *= 2;
    S->num_co++;
    return id;
  } else {
    for (int i = 0; i < S->capacity; ++i) {
      int id = (i + S->capacity) % S->capacity;
      if (S->co[id] == NULL) {
        S->co[id] = co;
        S->num_co++;
        return id;
      }
    }
  }
  assert(0);
  return -1;
}

static void mainfunc(uint32_t low32, uint32_t hi32) {
  uintptr_t ptr = (uintptr_t)low32 | ((uintptr_t)hi32) << 32;
  struct Schedule* S = (struct Schedule* )ptr;
  int id = S->running_id;
  struct Coroutine* C = S->co[id];
  C->func(S, C->ud);
  _co_delete(C);
  S->co[id] = NULL;
  S->num_co--;
  S->running_id = -1;
} // TODO

void coroutine_resume(struct Schedule* S, int id) {
  assert(S->running_id == -1);
  assert(id >= 0 && id < S->capacity);

  struct Coroutine* C = S->co[id];
  if (C == NULL)
    return ;

  int status = C->status;
  switch(status) {
    case COROUTINE_STATUS_READY: {
      getcontext(&C->context);
      C->context.uc_stack.ss_sp = S->stack;
      C->context.uc_stack.ss_size = STACK_SIZE;
      C->context.uc_link = &S->context;
      S->running_id = id;
      C->status = COROUTINE_STATUS_RUNNING;

      uintptr_t ptr = (uintptr_t)S;
      makecontext(&C->context, (void (* )(void)) mainfunc, 2, (uint32_t)ptr, (uint32_t)(ptr >> 32));
      swapcontext(&S->context, &C->context);
      break;
    }
    case COROUTINE_STATUS_SUSPEND: {
      memcpy(S->stack + STACK_SIZE - C->size, C->stack, C->size);
      S->running_id = id;
      C->status = COROUTINE_STATUS_RUNNING;
      swapcontext(&S->context, &C->context);
      break;
    }
    default:
      assert(0);
  }
}

static void _save_stack(struct Coroutine* C, char* top) {
  char dummy = 0;
  assert(top - & dummy <= STACK_SIZE);
  if (C->capacity < top - &dummy) {
    free(C->stack);
    C->capacity = top - &dummy;
    C->stack = malloc(C->capacity);
  }
  C->size = top - &dummy;
  memcpy(C->stack, &dummy, C->size);
}

void coroutine_yield(struct Schedule* S) {
  int id = S->running_id;
  assert(id >= 0);

  struct Coroutine* C = S->co[id];
  assert((char* )&C > S->stack);

  _save_stack(C, S->stack + STACK_SIZE);

  C->status = COROUTINE_STATUS_SUSPEND;
  S->running_id = -1;

  swapcontext(&C->context, &S->context);
}

int coroutine_status(struct Schedule* S, int id) {
  assert(id >= 0 && id < S->capacity);

  if(S->co[id] == NULL) {
    return COROUTINE_STATUS_DEAD;
  }
  return S->co[id]->status;
}

int coroutine_running(struct Schedule* S) {
  return S->running_id;
}

