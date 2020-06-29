#include <stdio.h>
#include <string.h>
#include <assert.h>


// myself implement strcpy fucntion
char* my_strcpy(char* dest, const char* src) {
  assert((dest != NULL) && (src != NULL));
  char* addr = dest;
  while ((*dest++ = *src++) != '\0')
    ;
  return addr;
}


int main() {
  char src[40];
  char dest[100];
  memset(dest, '\0', sizeof(dest));
  strcpy(src, "hello world");
  strcpy(dest, src);
  printf("Result: %s\n", dest);

  char my_src[40];
  char my_dest[100];
  memset(my_dest, '\0', sizeof(my_dest));
  my_strcpy(my_src, "hello world");
  my_strcpy(my_dest, my_src);
  printf("my Result: %s\n", my_dest);

  return 0;
}

