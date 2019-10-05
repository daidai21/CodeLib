/* =============================================================================
> File Name: function_vfork.c
> Author: DaiDai
> Mail: daidai4269@aliyun.com
> Created Time: Tue 17 Sep 2019 05:52:07 PM CST
============================================================================= */


/*
  child prcess first executes, address space share
*/


#include <stdio.h>
#include <unistd.h>


int glob_var = 0;


int main () {
  int var = 0;
  pid_t pid;

  printf("brfore vfork\n");
  if ((pid = vfork()) < 0) {
    printf("vfork error\n");
  } else if (pid == 0) {
    ++glob_var;
    ++var;
    _exit(0);
  } else {
    printf("pid = %d, glab_var = %d, var = %d\n", getpid(), glob_var, var);
    _exit(0);
  }
}
