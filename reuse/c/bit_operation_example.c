#include "./bit_operation.h"

#include <stdio.h>


int main() {
  int n1 = 5;
  printf("%d\n", n1);
  printf("\nbit count: %d %d\n", bit_count_one(n1), bit_count_zero(n1));
  print_binary(n1);
  n1 = number_complement(n1);
  printf("\n%d\n", n1);
  print_binary(n1);
  printf("\nbit count: %d %d\n", bit_count_one(n1), bit_count_zero(n1));

  int n2 = ~n1;
  printf("\n%d\n", n2);
  print_binary(n2);

  return 0;
}

