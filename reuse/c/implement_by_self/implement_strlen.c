#include <stdio.h>
#include <string.h>


int my1_strlen(char* s) {
  char* t;
  int size = 0;
  for (t = s; *t != '\0'; ++t) {
    ++size;
  }
  return size;
}

int my2_strlen(char* s) {
  char* t;
  for (t = s; *t != '\0'; ++t) ;
  return t - s;
}

int my3_strlen(char* s) {
  if (*s == '\0')
    return 0;
  else
    return 1 + my3_strlen(s + 1);
}

int main() {
  char* tmp = "hello world";
  printf("strlen: %lu\n", strlen(tmp));
  printf("my1_strlen: %d\n", my1_strlen(tmp));
  printf("my2_strlen: %d\n", my2_strlen(tmp));
  printf("my3_strlen: %d\n", my3_strlen(tmp));

  return 0;
}

