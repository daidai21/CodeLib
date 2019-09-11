/* =============================================================================
> File Name: set_process_id_infor.c
> Author: DaiDai
> Mail: daidai4269@aliyun.com
> Created Time: Mon 09 Sep 2019 09:36:29 PM CST
============================================================================= */



/* 进程标示 */

#include <unistd.h>

int setuid(uid_t uid);
int setpid(gid_t gid);

int setreuid(uid_t ruid, uid_t euid);
int setregid(gid_t rgid, uid_t egid);

int seteuid(uid_t uid);
int setegid(uid_t gid);

/* 加入一个现有的进程组或者创建一个新进程组 */

#include<unistd.h>
int setpgid(pid_t pid,pid_t pgid);
