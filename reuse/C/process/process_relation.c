/* =============================================================================
> File Name: process_relation.c
> Author: DaiDai
> Mail: daidai4269@aliyun.com
> Created Time: Thu 12 Sep 2019 05:51:38 PM CST
============================================================================= */


// 进程组

/////////////////////////////////////////////////////////////
// getpgrp/getpgid函数：获取进程所属的进程组：

#include<unistd.h>
pid_t getpgrp(void);
pid_t getpgid(pid_t pid);
// setpgid函数：加入一个现有的进程组或者创建一个新进程组

#include<unistd.h>
int setpgid(pid_t pid,pid_t pgid);

// 会话
/////////////////////////////////////////////////////////////
// setsid函数：创建一个新会话

#include<unistd.h>
pid_t setsid(void);



// getsid函数：返回进程所在的会话ID（会话ID等于会话首进程的进程组ID，会话首进程总是进程组的组长进程，因此它也等于会话首进程的进程ID）

#include<unistd.h>
pid_t getsid(pid_t pid);


// 作业控制
/////////////////////////////////////////////////////////////
tcgetpgrp/tcsetpgrp函数：获取/设置当前进程所在会话的前台进程组ID

#include<unistd.h>
pid_t tcgetpgrp(int fd);
int tcsetpgrp(int fd,pid_t pgrpid);


tcgetsid函数：获取会话首进程的进程组ID（也就是会话ID）

#include<termios.hh>
pid_t tcgetsid(int fd);


