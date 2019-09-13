/* =============================================================================
> File Name: env_table.c
> Author: DaiDai
> Mail: daidai4269@aliyun.com
> Created Time: Sat 07 Sep 2019 03:02:46 PM CST
============================================================================= */


#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[], char* envp[]) {
  printf("num of param is %d\n", argc);
  for (int i = 0; i < argc; ++i)
    printf("param %d is %s\n", i, argv[i]);

  for (int i = 0; envp[i] != NULL; ++i)
    printf("envp  %d  is  %s\n", i, envp[i]);

  /* get USER from envp */
  printf("USER is  %s  in envp\n", getenv("USER"));

  return 0;
}
