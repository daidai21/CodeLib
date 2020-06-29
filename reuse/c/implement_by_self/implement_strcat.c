#include <stdio.h>
#include <string.h>
#include <assert.h>


char* my_strcat(char* destination, const char* source) {
  assert(destination != NULL);
  assert(source      != NULL);
  char* result = destination;
  while (*destination != '\0') {
    destination++;
  }
  while((*destination++ = *source++) != '\0') ;
  return result;
}


int main() {
  char tmp1[100];
  strcat(tmp1, "hello world");
  printf("strcpy: %s\n", tmp1);

  char tmp2[100];
  my_strcat(tmp2, "hello world");
  printf("my_strcpy: %s\n", tmp2);

  return 0;
}

