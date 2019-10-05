/* =============================================================================
> File Name: function_wait_and_waitpid.c
> Author: DaiDai
> Mail: daidai4269@aliyun.com
> Created Time: Tue 17 Sep 2019 06:06:31 PM CST
============================================================================= */


/*
  API
    #include <stdio.h>
    #include <sys/types.h>
    #include <sys/wait.h>
    #include <time.h>
    #include <sys/resource.h>
    pid_t wait3(int *status, int options, struct rusage *rusage);
    pid_t wait4(pid_t pid, int *status, int options, struct rusage *rusage);
*/


#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>


void example_wait() {
  pid_t pid;
  int status;
  int i;
  if ((pid = fork()) < 0)
    printf("fork error!\n");
  else if (pid == 0) {
    printf("this is child process, pid = %d\n", pid);
    exit(5);
  } else {
    sleep(1);
    printf("this is parent process, wait for child...\n");
    pid = wait(&status);
    i = WEXITSTATUS(status);
    printf("child pid = %d, exit status = %d\n", pid, i);
  }
}

void example_waitpid() {
  pid_t pid;
  pid = fork();
  if (pid < 0) {
    printf("fork error\n");
    exit(1);
  } else if (pid == 0) {
    for (int i = 3; i > 0; --i) {
      printf("this is the child %d\n", i);
      sleep(1);
    }
  } else {
    int stat_val;
    waitpid(pid, &stat_val, 0);
    if (WIFEXITED(stat_val))
      printf("child exited with code %d\n", WEXITSTATUS(stat_val));
    else if (WIFSIGNALED(stat_val)) {
      printf("child terminated abnormally, signal %d\n", WTERMSIG(stat_val));
    }
  }
}

int main() {
  printf("+++++ wait +++++\n");
  example_wait();
  printf("+++++ waitpid +++++\n");
  example_waitpid();

  return 0;
}
