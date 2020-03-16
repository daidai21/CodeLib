/* gcc run_add_cmd_times_every_second.c -d WIN32 */

#ifdef UNIX
#   include <pthread.h>
#elif WIN32
#   include <windows.h>
#endif
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


volatile long long int times = 0;
long long int* p_times;


void* func_add_in_stack() {
  while (1)
    times++;
}


void* func_add_in_heap() {
  while (1)
    (*p_times)++;
}


int main() {
  pthread_t id;

  if (pthread_create(&id, NULL, func_add_in_stack, NULL) != 0) {
    printf("Error: pthread_create() \n");
    return 0;
  }
  sleep(1);
  pthread_cancel(id);

  p_times = (long long int* ) malloc(sizeof(long long int));
  *p_times = 0;
  if (pthread_create(&id, NULL, func_add_in_heap, NULL) != 0) {
    printf("Error: pthread_create() \n");
    free(p_times);
    return 0;
  }
  sleep(1);
  pthread_cancel(id);
  free(p_times);

  printf("Total: %lld times add every second in stack. \n", times);
  printf("Total: %lld times add every second in heap. \n", *p_times);

  return 0;
}
