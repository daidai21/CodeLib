/* =============================================================================
> File Name: thread_sync_attr.c
> Author: DaiDai
> Mail: daidai4269@aliyun.com
> Created Time: Thu 12 Sep 2019 05:26:51 PM CST
============================================================================= */


/*
  书上是线程控制
*/

// 线程重入
/////////////////////////////////////////////////////




// 为FILE对象加锁/解锁
#include<stdio.h>
int ftrylockfile(FILE *fp);
void flockfile(FILE *fp);
void funlockfile(FILE *fp);


// 不加锁版本的基于字符的标准IO函数：

#include<stdio.h>
int getchar_unlocked(void);
int getc_unlocked(FILE *fp);
int putchar_unlocked(int c);
int putc_unlocked(int c,FILE *fp);


// 线程特定数据
/////////////////////////////////////////////////


// 创建线程私有数据的键
#include<pthread.h>
int pthread_key_create(pthread_key_t *keyp,void (*destructor)(void*));


// 取消键与线程私有数据值之间绑定

#include<pthread.h>
int pthread_key_delete(pthread_key_t key);
// pthread_once函数：
#include<pthread.h>
pthread_once_t initflag=PTHREAD_ONCE_INIT;
int pthread_once(pthread_once_t *initflag,void (*initfn)(void));


// 将键与线程私有数据绑定 / 根据键获取它绑定的线程私有数据

#include<pthread.h>
void *pthread_getspecific(pthread_key_t key);
int pthread_setspecific(pthread_key_t key,const void*value);


// 取消选项
/////////////////////////////////////////////////



// pthread_testcancel函数：手动添加取消点

#include<pthread.h>
void pthread_testcancel(void);
// pthread_setcancelstate函数：设置线程的可取消状态

#include<pthread.h>
int pthread_setcancelstate(int state,int *oldstate);

// pthread_setcanceltype函数：修改取消类型

#include<pthread.h>
int pthread_setcanceltype(int type,int *oldtype);


// 线程和信号
/////////////////////////////////////////////////
// pthread_sigmask函数：修改线程的信号屏蔽字

#include<signal.h>
int pthread_sigmask(int how,const sigset_t *restrict set,sigset_t *restrict oset);
// 线程可以通过sigwait来等待一个或者多个信号的出现：

#include<signal.h>
int sigwait(const sigset_t *restrict set,int *restrict signop);


// 要把信号发送给线程，可以用pthread_kill

#include<signal.h>
int pthread_kill(pthread_t thread,int signo);


// 线程和 fork
/////////////////////////////////////////////////
// pthread_atfork 函数：建立fork处理程序

#include<pthread.h>
int pthread_atfork(void (*prepare)(void),void (*parent)(void),void (*child)(void));


//  线程和IO
/////////////////////////////////////////////////
