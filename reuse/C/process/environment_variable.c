/* =============================================================================
> File Name: environment_variable.c
> Author: DaiDai
> Mail: daidai4269@aliyun.com
> Created Time: Tue 17 Sep 2019 09:26:50 PM CST
============================================================================= */


/*
  API
    #include<stdlib.h>
    int putenv(char *str);
    int setenv(const char *name,const char *value,int rewrite);
    int unsetenv(const char *name);
*/


#include <stdio.h>
#include<stdlib.h>


int main() {
  printf("environment variable USER %s\n", getenv("USER"));
  setenv("USER", "test", 1);
  printf("environment variable USER %s\n", getenv("USER"));

  return 0;
}
