/* =============================================================================
> File Name: exec_functions.c
> Author: DaiDai
> Mail: daidai4269@aliyun.com
> Created Time: Mon 09 Sep 2019 09:41:24 PM CST
============================================================================= */


#include <stdio.h>

#include <unistd.h>


int execl(const char *path, const char *arg, ...);
int execle(const char *path, const char *arg, ..., char *const envp[]);
int execv(const char *path, char *const argv[]);
int execve(const char *path, char *const argv[], char *const envp[]);

int execlp(const char *file, const char *arg, ...);
int execvp(const char *file, char *const argv[]);

int fexecve(int fd, char *const argv[], char *const envp[]);
