/* =============================================================================
> File Name: sys_config.c
> Author: DaiDai
> Mail: daidai4269@aliyun.com
> Created Time: Mon 09 Sep 2019 03:56:19 PM CST
============================================================================= */


#include <stdio.h>




/*函数getrlimit和setrlimit */

#include <sys/resource.h>

int getrlimit(int resource, struct rlimit *rlim);
int setrlimit(int resource, const struct rlimit *rlim);
