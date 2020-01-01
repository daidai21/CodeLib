/* =============================================================================
> File Name: bit_operation.h
> Author: DaiDai
> Mail: daidai4269@aliyun.com
> Created Time: Sat 09 Nov 2019 07:10:12 PM CST
============================================================================= */


#include <stdio.h>


int number_complement(const int num) {
  unsigned int mask = ~0;
  while (num & mask)
    mask <<= 1; 
  return ~num & ~mask;
}

void print_binary(unsigned int num) {
  if (num > 1)
    print_binary(num >> 1);
  printf("%d", num & 1);
}

int bit_count_one(unsigned int num) {
  unsigned int cnt = 0;
  for (; num > 0; num >>= 1)
    cnt += num & 1;
  return cnt;
}

int bit_count_zero(unsigned int num) {
  unsigned int cnt = 0;
  for (; num > 0; num >>= 1)
    cnt += num & 0;
  return cnt;
}

