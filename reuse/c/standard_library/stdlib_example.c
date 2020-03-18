#include <stdio.h>
#include <stdlib.h>


void atexit_func() {
  printf("atexit_func()\n");
}

int main(int argc, char* argv[]) {

  printf("exiting main()\n");
  atexit(atexit_func);

  return 0;
}
