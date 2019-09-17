/* =============================================================================
> File Name: get_process_id_information.c
> Author: DaiDai
> Mail: daidai4269@aliyun.com
> Created Time: Mon 09 Sep 2019 09:30:33 PM CST
============================================================================= */


#include <stdio.h>
#include <unistd.h>


int main() {
  printf("process id %d\n", getpid());
  printf("parent process id %d\n", getppid());
  printf("actual user id of call process %d\n", getuid());
  printf("effective user id of call process %d\n", geteuid());
  printf("actual group of call process %d\n", getgid());
  printf("effective group of call process  %d\n", getegid());

  return 0;
}
