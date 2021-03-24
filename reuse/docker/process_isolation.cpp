#define _GNU_SOURCE
#include <sched.h>
#include <signal.h>
#include <stdio.h>
#include <sys/mount.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
/* 定义一个给 clone 用的栈，栈大小1M */
#define STACK_SIZE (1024 * 1024)
static char container_stack[STACK_SIZE];

char* const container_args[] = {
    "/bin/bash",
    NULL};

int container_main(void* arg) {
  printf("容器进程[%5d] ----进入容器!\n", getpid());
  mount("proc", "/proc", "proc", 0, NULL);
  /**执行/bin/bash */
  execv(container_args[0], container_args);
  printf("出错啦!\n");
  return 1;
}

int main() {
  printf("宿主机进程[%5d] - 开始一个容器!\n", getpid());
  /* 调用clone函数 */
  int container_pid = clone(container_main, 
                            container_stack + STACK_SIZE, 
                            CLONE_NEWPID | CLONE_NEWNS | SIGCHLD, 
                            NULL);
  /* 等待子进程结束 */
  waitpid(container_pid, NULL, 0);
  printf("宿主机 - 容器结束!\n");
  return 0;
}


// TODO: wait ubuntu_docker image
