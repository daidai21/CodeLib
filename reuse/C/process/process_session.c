/* =============================================================================
> File Name: process_session.c
> Author: DaiDai
> Mail: daidai4269@aliyun.com
> Created Time: Thu 19 Sep 2019 02:01:41 PM CST
============================================================================= */


/*
  API
    pid_t setsid(void); // create a new session
*/


#include <stdio.h>
#include<unistd.h>


int main() {
  pid_t curr_pid = getpid();
  printf("current process pid = %d\n", curr_pid);
  printf("current session id  = %d\n", getsid(curr_pid));

  return 0;
}
