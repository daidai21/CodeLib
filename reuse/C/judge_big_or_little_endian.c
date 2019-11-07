/* =============================================================================
> File Name: judge_big_or_little_endian.c
> Author: DaiDai
> Mail: daidai4269@aliyun.com
> Created Time: Sun 03 Nov 2019 07:40:16 PM CST
============================================================================= */


#include <stdio.h>


int main() {
  unsigned int i = 1;
  char* c = (char* )& i;
  if (*c)
    printf("Little endian\n");
  else
    printf("Big endian\n");

  return 0;
}
