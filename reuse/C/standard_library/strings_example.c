#include <stdio.h>
#include <string.h>

#include <strings.h>


int main(int argc, char* argv[]) {
  // diff bzero() and memset()
  char str[] = "hello";
  puts(str);
  memset(str, '0', 5);
  puts(str);
  strcpy(str, "hello");
  puts(str);
  bzero(str, sizeof(str));
  puts(str);

  return 0;
}
