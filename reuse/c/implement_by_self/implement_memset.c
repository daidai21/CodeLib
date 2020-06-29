#include <stdio.h>
#include <string.h>


void* my_memset(void* ptr, int value, size_t num) {
  void* result = ptr;
  while (num--) {
    *(char*)ptr = (char)value;
    ptr = (char*)ptr + 1;
  }
  return result;
}


int main() {
  char tmp1[] = "hello world";
  memset(tmp1, '_', 5);
  printf("%s\n", tmp1);

  char tmp2[] = "hello world";
  my_memset(tmp2, '_', 5);
  printf("%s\n", tmp2);

  return 0;
}

