/* =============================================================================
> File Name: process.c
> Author: DaiDai
> Mail: daidai4269@aliyun.com
> Created Time: Mon 09 Sep 2019 03:55:35 PM CST
============================================================================= */


#include <stdio.h>



/*函数fork*/
#include <unistd.h>

pid_t fork(void);

/* 函数vfork*/

vfork();


/* 函数wait和waitpid */

#include <sys/wait.h>

pid_t wait(int* statloc);
pid_t waitpid(pid_t pid, int* statloc, int options);

/* */

#include <sys/wait.h>

int waitid(idtype_t idtype, id_t id, siginfo_t* infop, int options);

/* */

#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>
#include <sys/resource.h>

pid_t wait3(int *status, int options,
            struct rusage *rusage);
 
pid_t wait4(pid_t pid, int *status, int options,
            struct rusage *rusage);


/*  */

#include <stdlib.h>

int system(const char* cmdstring);


/*  */

#include <sys/acct.h>



/*　用户标示 */

#include <unistd.h>

char *getlogin(void);


/*　进程调度 */
#include <unistd.h>
int nice(int incr);

#include <sys/resource.h>

int getpriority(int which, id_t who);

#include <sys/resource.h>

int setpriority(int which, id_t who, int value);


/*　进程时间 */

#include <sys/times.h>

clock_t times(struct tms* buf);

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

