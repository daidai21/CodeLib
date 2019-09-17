/* =============================================================================
> File Name: function_exec.c
> Author: DaiDai
> Mail: daidai4269@aliyun.com
> Created Time: Tue 17 Sep 2019 06:08:13 PM CST
============================================================================= */


/*
  test only one example

  API:
    int execl(const char *path, const char *arg, ...);
    int execle(const char *path, const char *arg, ..., char *const envp[]);
    int execv(const char *path, char *const argv[]);
    int execve(const char *path, char *const argv[], char *const envp[]);
    int execlp(const char *file, const char *arg, ...);
    int execvp(const char *file, char *const argv[]);
    int fexecve(int fd, char *const argv[], char *const envp[]);
*/


#include <stdio.h>
#include <unistd.h>


int main() {
  char* argv[] = {"ls", "-al", "/home/", NULL};
  char* envp[] = {0, NULL};
  printf("path %s include:", argv[2]);
  execve("/bin/ls", argv, envp);

  return 0;
}
