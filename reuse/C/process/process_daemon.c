/* =============================================================================
> File Name: process_daemon.c
> Author: DaiDai
> Mail: daidai4269@aliyun.com
> Created Time: Thu 12 Sep 2019 05:34:10 PM CST
============================================================================= */



// syslog设施的接口函数如下：

#include<syslog.h>
void openlog(const char *ident,int option,int facility);
void syslog(int priority,const char *format,...);
void closelog(void);
int setlogmask(int maskpri);

