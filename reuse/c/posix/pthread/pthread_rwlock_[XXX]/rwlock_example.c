/* ****************************************************************************
 * File Name   : rwlock_example.c
 * Author      : DaiDai
 * Mail        : daidai4269@aliyun.com
 * Created Time: 五  9/25 00:41:23 2020
 *************************************************************************** */

#include <pthread.h>

int counter = 0;
static pthread_rwlock_t rwlock;

void* th_read(void* arg) {
  pthread_rwlock_trywrlock(&rwlock);
  counter++;
  printf("---read %d: %lu: %d\n", arg, pthread_self(), counter);
  pthread_rwlock_unlock(&rwlock);
  return NULL;
}

void* th_write(void* arg) {
  pthread_rwlock_trywrlock(&rwlock);
  counter--;
  printf("---write %d: %lu: %d\n", arg, pthread_self(), counter);
  pthread_rwlock_unlock(&rwlock);
  return NULL;
}

int main() {
  pthread_t ths[10];
  pthread_rwlock_init(&rwlock, NULL);
  for (int i = 0; i < 2; i++) {
    pthread_create(&ths[i], NULL, th_write, (void*)i);
  }
  for (int i = 0; i < 8; i++) {
    pthread_create(&ths[i + 3], NULL, th_read, (void*)i);
  }
  for (int i = 0; i < 10; i++) {
    pthread_join(ths[i], NULL);
  }
  pthread_rwlock_destroy(&rwlock);
  printf("%d", counter);

  return 0;
}

