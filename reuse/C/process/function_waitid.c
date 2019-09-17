/* =============================================================================
> File Name: function_waitid.c
> Author: DaiDai
> Mail: daidai4269@aliyun.com
> Created Time: Tue 17 Sep 2019 06:07:18 PM CST
============================================================================= */


#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <stdlib.h>


int main() {
  pid_t pid;
  id_t id;
  int status;
  int ret;
  if ((pid = fork()) < 0) {
    printf("fork error\n");
    exit(1);
  } else if (pid == 0) {
    printf("child process, pid = %d\n", getpid());
    exit(8);
  } else {
    siginfo_t info;
    memset(&info, 0, sizeof(siginfo_t));
    ret = waitid(P_ALL, id, &info, WEXITED);
    if (ret < 0)
      printf("waitid error\n");
    if (info.si_code == CLD_EXITED)
      printf("si_code = CLD_EXITED\n");
    printf("si_status = %d\n", info.si_status);
  }

  return 0;
}
