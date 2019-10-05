/* =============================================================================
> File Name: function_fork.c
> Author: DaiDai
> Mail: daidai4269@aliyun.com
> Created Time: Tue 17 Sep 2019 05:41:40 PM CST
============================================================================= */


/*
  don't know if it is parent prcess or child prcess that executes first
*/


#include <stdio.h>
#include <unistd.h>


int main() {
  int count = 0;
  pid_t pid = fork();
  if (pid < 0)
    printf("fork error!\n");
  else if (pid == 0) {
    printf("this is child process, process id is %d\n", getpid());
    ++count;
  } else {
    printf("this is parent process, process id is %d\n", getpid());
    ++count;
  }
  printf("count is %d\n", count);
  /*
    copy on write
    so, count is 1
  */

  return 0;
}
