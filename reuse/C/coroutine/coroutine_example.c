/* =============================================================================
> File Name: coroutine_example.c
> Author: DaiDai
> Mail: daidai4269@aliyun.com
> Created Time: Thu 21 Nov 2019 05:38:13 PM CST
============================================================================= */


#include "coroutine.h"

#include <stdio.h>


struct Args {
  int n;
};


static void foo(struct Schedule* S, void* ud) {
  struct Args* arg = ud;
  int start = arg->n;
  for (int i = 0; i < 10; ++i) {
    printf("coroutine %d : %d\n", coroutine_running(S), start + i);
    coroutine_yield(S);
  }
}

static void test(struct Schedule* S) {
  struct Args arg1 = { 0 };
  struct Args arg2 = { 100 };

  int co1 = coroutine_new(S, foo, &arg1);
  int co2 = coroutine_new(S, foo, &arg2);

  printf("main start\n");
  while (coroutine_status(S, co1) && coroutine_status(S, co2)) {
    coroutine_resume(S, co1);
    coroutine_resume(S, co2);
  }
  printf("main end\n");
}


int main() {
  struct Schedule* S = coroutine_open();
  test(S);
  coroutine_close(S);

  return 0;
}

