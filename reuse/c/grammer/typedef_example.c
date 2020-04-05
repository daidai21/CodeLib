#include <stdio.h>


// typdef return-type (*function-type)(function-input-parameter-list)
typedef float (*p_func)(int, float);


float add_func(int a, float b) {
  return b + a;
}


int main(int argc, char* argv[]) {
  p_func f = add_func;
  float res;
  res = f(1, 1.1);
  printf("%.1f\n", res);

  return 0;
}

