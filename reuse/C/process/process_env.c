/* =============================================================================
> File Name: process_env.c
> Author: DaiDai
> Mail: daidai4269@aliyun.com
> Created Time: Thu 12 Sep 2019 05:48:24 PM CST
============================================================================= */


exit/_Exit/_exit函数：正常终止一个程序

#include<stdlib.h>
void exit(int status);
void _Exit(int status);
#include<unistd.h>
void _exit(int status);
// atexit函数：登记由exit函数调用的清理函数

#include<stdlib.h>
int atexit(void (*func) (void));

// 环境变量
///////////////////////////////////////////////////////////////
// getenv函数：获取环境变量的值：

#include<stdlib.h>
char *getenv(const char*name);
// putenv/setenv/unsetenv函数：设置环境变量的值

#include<stdlib.h>
int putenv(char *str);
int setenv(const char *name,const char *value,int rewrite);
int unsetenv(const char *name);

// setjmp 和 longjmp
///////////////////////////////////////////////////////////////

// setjmp/longjmp函数：非局部goto

#include<setjmp.h>
int setjmp(jmp_buf env);
void longjmp(jmp_buf env,int val);
// 进程资源限制
///////////////////////////////////////////////////////////////
// 每个进程都有一组资源限制，其中一些可以通过getrlimit/setrlimit函数查询和修改：

#include<sys/resource.h>
int getrlimit(int resource,struct rlimit *rlptr);
int setrlimit(int resource,struct rlimit *rlptr);
