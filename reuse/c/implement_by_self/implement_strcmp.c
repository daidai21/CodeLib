#include <stdio.h>
#include <string.h>


int my_strcmp(const char* s1, const char* s2) {
  while (*s1 && *s2 && (*s1 == *s2)) {
    s1++;
    s2++;
  }
  return *s1 - *s2;
}


int main() {
  char* tmp1 = "hello";
  char* tmp2 = "world";

  printf("strcmp: %d\n", strcmp(tmp1, tmp2));
  printf("my_strcmp: %d\n", my_strcmp(tmp1, tmp2));

  return 0;
}

