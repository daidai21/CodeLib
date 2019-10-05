/* =============================================================================
> File Name: process_relation.c
> Author: DaiDai
> Mail: daidai4269@aliyun.com
> Created Time: Thu 12 Sep 2019 05:51:38 PM CST
============================================================================= */


// TODO: not understand!!!!


#include <stdio.h>
#include <unistd.h>
#include <termios.h>
#include <signal.h>


static void judge() {
  pid_t pid = tcgetpgrp(STDIN_FILENO);
  if (pid < 0) {
    printf("tcgetpgrp error\n");
    return ;
  } else if (pid == getpgrp())
    printf("foreground\n");
  else
    printf("background\n");
}

int main(){
  pid_t spid;
  printf("tcgetsid=%d, pgrp=%d, sid=%d\n", tcgetsid(STDIN_FILENO), getpgrp(), getsid(getpid()));
  spid = tcgetsid(STDIN_FILENO);
  signal(SIGTTOU, SIG_IGN);
  judge();
  int result;
  result = tcsetpgrp(STDIN_FILENO, getpgrp());
  if(result < 0){
    perror("tcsetpgrp error\n");
    return -1;
  }
  judge();
  result = tcsetpgrp(STDIN_FILENO, spid);
  judge();

  return 0;
}
