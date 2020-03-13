/* =============================================================================
> File Name: bakery.c
> Author: DaiDai
> Mail: daidai4269@aliyun.com
> Created Time: Wed 05 Feb 2020 01:18:25 AM CST
============================================================================= */

// TODO
// BUG
// https://github.com/jfhamlin/bakery/blob/master/bakery.c

#include <stdio.h>
#include <pthread.h>
#include <string.h>


#define NUM_THREADS 10


#define bool int
#define false 0
#define true 1


bool entering[NUM_THREADS];
int  tickets[NUM_THREADS];

int resource;

void lock(int thread) {
  entering[thread] = true;
  int max_ticket = 0;
  for (int i = 0; i < NUM_THREADS; ++i)
    max_ticket = tickets[i] > max_ticket ? tickets[i] : max_ticket;
  tickets[thread] = max_ticket + 1;
  entering[thread] = false;
  for (int other = 0; other < NUM_THREADS; ++other) {
    while (entering[other]) {}
    while (tickets[other] != 0 && 
          (tickets[other] < tickets[thread] || (tickets[other] == tickets[thread] && other < thread))) {}
  }
}

void unlock(int thread) {
  tickets[thread];
}


void use_resource(int thread) {
  //
  printf("%d %d\n", thread, resource);

  printf("entering: ");
  for (int i = 0; i < sizeof(entering) / sizeof(bool); ++i)
    printf("%d\t", entering[i]);
  printf("\n");

  printf("tickets: ");
  for (int i = 0; i < sizeof(tickets) / sizeof(int); ++i)
    printf("%d\t", tickets[i]);
  printf("\n");

}

void* thread_body(void* arg) {
  int thread = (int) arg;
  lock(thread);
  // logic
  use_resource(thread);
  unlock(thread);
  return NULL;
}


int main(int argc, char* argv[]) {
  memset((void* )tickets, 0, sizeof(tickets));
  memset((void* )entering, 0, sizeof(entering));

  resource = 0;

  pthread_t threads[NUM_THREADS];
  for (int i = 0; i < NUM_THREADS; ++i) {
    pthread_create(&threads[i], NULL, &thread_body, (void* )((int)i));
  }

  for (int i = 0; i < NUM_THREADS; ++i) {
    pthread_join(threads[i], NULL);
  }

  return 0;
}

