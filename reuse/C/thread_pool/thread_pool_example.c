/* =============================================================================
> File Name: thread_pool_example.c
> Author: DaiDai
> Mail: daidai4269@aliyun.com
> Created Time: Fri 29 Nov 2019 03:31:35 PM CST
============================================================================= */


#include "thread_pool.h"

#include <stdio.h>
#include <pthread.h>


void task1(){
  printf("Thread #%u working on task1\n", (int)pthread_self());
}


void task2(){
  printf("Thread #%u working on task2\n", (int)pthread_self());
}


int main() {
  puts("Making threadpool with 4 threads");
  thread_pool_p thpool = thread_pool_init(4);

  puts("Adding 40 tasks to threadpool");
  int i;
  for (i=0; i<20; i++){
    thread_pool_add_work(thpool, (void*)task1, NULL);
    thread_pool_add_work(thpool, (void*)task2, NULL);
  };

  puts("Killing threadpool");
  thread_pool_destroy(thpool);

}

