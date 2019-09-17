/* =============================================================================
> File Name: process.c
> Author: DaiDai
> Mail: daidai4269@aliyun.com
> Created Time: Mon 09 Sep 2019 03:55:35 PM CST
============================================================================= */


// 创建一个新会话
#include<unistd.h>
pid_t setsid(void);

// 返回进程所在的会话ID
#include<unistd.h>
pid_t getsid(pid_t pid);

// 获取/设置当前进程所在会话的前台进程组ID
#include<unistd.h>
pid_t tcgetpgrp(int fd);
int tcsetpgrp(int fd,pid_t pgrpid);

// 获取会话首进程的进程组ID

#include<termios.h>
pid_t tcgetsid(int fd);


exit/_Exit/_exit函数：正常终止一个程序

#include<stdlib.h>
void exit(int status);
void _Exit(int status);
#include<unistd.h>
void _exit(int status);
// atexit函数：登记由exit函数调用的清理函数

#include<stdlib.h>
int atexit(void (*func) (void));
