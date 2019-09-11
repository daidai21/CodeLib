/* =============================================================================
> File Name: call_back_function.c
> Author: DaiDai
> Mail: daidai4269@aliyun.com
> Created Time: Mon 09 Sep 2019 06:11:32 PM CST
============================================================================= */


#include <stdio.h>
#include <stdlib.h>


void populate_array(int* array, size_t array_size, int (*get_next_val)(void)) {
  for (size_t i = 0; i < array_size; ++i)
    array[i] = get_next_val();
}

int get_next_random_val() {
  return rand();
}

int main() {
  int my_array[10];
  populate_array(my_array, 10, get_next_random_val);
  for (int i = 0; i < 10; ++i)
    printf("%d ", my_array[i]);
  printf("\n");
  return 0;
}
