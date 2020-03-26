#include "hash_function.h"

#include <stdio.h>
#include <stdlib.h>


int main(int argc, char* argv[]) {
  printf("1 -> %u\n", RS_hash("1"));
  printf("2 -> %u\n", RS_hash("2"));
  printf("3 -> %u\n", RS_hash("3"));
  printf("4 -> %u\n", RS_hash("4"));
  printf("5 -> %u\n", RS_hash("5"));
  printf("6 -> %u\n", RS_hash("6"));
  printf("7 -> %u\n", RS_hash("7"));
  printf("8 -> %u\n", RS_hash("8"));
  printf("9 -> %u\n", RS_hash("9"));
  printf("0 -> %u\n", RS_hash("0"));
  printf("11 -> %u\n", RS_hash("11"));

  return 0;
}

