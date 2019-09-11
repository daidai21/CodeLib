/* =============================================================================
> File Name: get_process_id_infor.c
> Author: DaiDai
> Mail: daidai4269@aliyun.com
> Created Time: Mon 09 Sep 2019 09:30:33 PM CST
============================================================================= */



/* 进程标示 */

#include <unistd.h>

pid_t getpid(void);
uid_t getuid(void);
uid_t geteuid(void);
gid_t getgid(void);
gid_t getegid(void);

/* 获取进程所属的进程组 */
pid_t getpgrp(void);
pid_t getpgid(pid_t pid);
