/* =============================================================================
> File Name: dynamic_array.c
> Author: DaiDai
> Mail: daidai4269@aliyun.com
> Created Time: Wed 11 Sep 2019 04:32:30 PM CST
============================================================================= */


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


void output(int* p, int n) {
  for (int i = 0; i < n; ++i)
    printf("%d ", p[i]);
  printf("size: %d\n", n);

}

bool is_null(int* p) {
  return p == NULL;
}

int main () {
  // init
  int n = 4;
  int* p = malloc(sizeof(int) * n);
  for (int i = 0; i < n; ++i)
    p[i] = i + 43;
  output(p, n);
  printf("%s\n", is_null(p) ? "true" : "false");

  // size increase
  int n1 = n + 2;
  int* p1 = realloc(p, sizeof(int) * n1);
  for (int i = n; i < n1; ++i) {
    p1[i] = -i;
  }
  output(p1, n1);

  // size decrease
  int n2 = n - 2;
  int* p2 = realloc(p, sizeof(int) * n2);
  output(p1, n2);

  // recovery
  free(p);
  printf("%d %d %d\n", p[0], p[1], p[20]); // visit of memory leak method

  return 0;
}
