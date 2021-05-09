/* ****************************************************************************
 * File Name   : msg_que.c
 * Author      : DaiDai
 * Mail        : daidai4269@aliyun.com
 * Created Time: 日  5/ 2 23:52:01 2021
 *************************************************************************** */

#include "./msg_que.h"

#include <errno.h>
#include <pthread.h>
#include <stdlib.h>

struct __msg_que {
  // 实际消息队列的最大存储量为 2 * msg_max
  size_t msg_max;
  size_t msg_cnt;
  int linkoff;
  int nonblock;
  // head1 和 head2 为 get_list和put_list，相互交换
  void* head1;
  void* head2;
  void** get_head;
  void** put_head;
  void** put_tail;
  pthread_mutex_t get_mtx;
  pthread_mutex_t put_mtx;
  pthread_cond_t get_cond;
  pthread_cond_t put_cond;
};

msg_que_t* msg_que_create(size_t maxlen, int linkoff) {
  msg_que_t* que = (msg_que_t*)malloc(sizeof(msg_que_t));
  int ret;
  if (!que) {
    return NULL;
  }
  ret = pthread_mutex_init(&que->get_mtx, NULL);
  if (ret == 0) {
    ret = pthread_mutex_init(&que->put_mtx, NULL);
    if (ret == 0) {
      ret = pthread_cond_init(&que->get_cond, NULL);
      if (ret == 0) {
        ret = pthread_cond_init(&que->put_cond, NULL);
        if (ret == 0) {
          que->msg_max = maxlen;
          que->linkoff = linkoff;
          que->head1 = NULL;
          que->head2 = NULL;
          que->get_head = &que->head1;
          que->put_head = &que->head2;
          que->put_tail = &que->head2;
          que->msg_cnt = 0;
          que->nonblock = 0;
          return que;
        }
        pthread_cond_destroy(&que->get_cond);
      }
      pthread_mutex_destroy(&que->put_mtx);
    }
    pthread_mutex_destroy(&que->get_mtx);
  }
  errno = ret;
  free(que);
  return NULL;
}

static size_t __msg_que_swap(msg_que_t* que) {
  void** get_head = que->get_head;
  size_t cnt;
  que->get_head = que->put_head;
  pthread_mutex_lock(&que->put_mtx);
  while (que->msg_cnt == 0 && !que->nonblock) {
    pthread_cond_wait(&que->get_cond, &que->put_mtx);
  }
  cnt = que->msg_cnt;
  if (cnt > que->msg_max - 1) {
    pthread_cond_broadcast(&que->put_cond);
  }
  que->put_head = get_head;
  que->put_tail = get_head;
  que->msg_cnt = 0;
  pthread_mutex_unlock(&que->put_mtx);
  return cnt;
}

void msg_que_put(msg_que_t* que, void* msg) {
  void** link = (void**)((char*)msg + que->linkoff);
  *link = NULL;
  pthread_mutex_lock(&que->put_mtx);
  while (que->msg_cnt > que->msg_max - 1 && !que->nonblock) {
    pthread_cond_wait(&que->put_cond, &que->put_mtx);
  }
  *que->put_tail = link;
  que->put_tail = link;
  que->msg_cnt++;
  pthread_mutex_unlock(&que->put_mtx);
  pthread_cond_signal(&que->get_cond);
}

void* msg_que_get(msg_que_t* que) {
  void* msg;
  pthread_mutex_lock(&que->get_mtx);
  if (*que->get_head || __msg_que_swap(que) > 0) {
    msg = (char*)*que->get_head - que->linkoff;
    *que->get_head = *(void**)*que->get_head;
  } else {
    msg = NULL;
    // ENOENT: Error NO ENTry
    errno = ENOENT;
  }
  pthread_mutex_unlock(&que->get_mtx);
  return msg;
}

void msg_que_set_nonblock(msg_que_t* que) {
  que->nonblock = 1;
  pthread_mutex_lock(&que->put_mtx);
  // 唤醒指定条件变量上被阻塞的线程
  pthread_cond_signal(&que->get_cond);
  // 解除阻塞当前指定条件变量上阻塞的线程
  pthread_cond_broadcast(&que->put_cond);
  pthread_mutex_unlock(&que->put_mtx);
}

void msg_que_set_block(msg_que_t* que) {
  que->nonblock = 0;
}

void msg_que_destroy(msg_que_t* que) {
  pthread_cond_destroy(&que->put_cond);
  pthread_cond_destroy(&que->get_cond);
  pthread_mutex_destroy(&que->put_mtx);
  pthread_mutex_destroy(&que->get_mtx);
  free(que);
}
