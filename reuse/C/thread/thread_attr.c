/* =============================================================================
> File Name: thread_attr.c
> Author: DaiDai
> Mail: daidai4269@aliyun.com
> Created Time: Thu 12 Sep 2019 05:17:17 PM CST
============================================================================= */


#include <stdio.h>


// 初始化/销毁互斥量	属性

#include<pthread.h>
int pthread_mutexattr_init(pthread_mutexattr_t *attr);
int pthread_mutexattr_destroy(pthread_mutexattr_t *attr);

// 获取/设置线程的分离状态属性

#include<pthread>
int pthread_attr_getdetachstate(const pthread_attr_t *restrict attr,
	int *detachstate);
int pthread_attr_setdetachsetate(const pthread_attr_t *restrict attr,
	int detachstate);
// 获取/设置线程的线程栈属性

#include<pthread.h>
int pthread_attr_getstack(const pthread_attr_t *restrict attr,
	void ** restrict stackaddr,size_t *restrict stacksize);
int pthread_attr_setstack(pthread_attr_t *attr,
	void *stackaddr,size_t stacksize);

// 获取/设置线程的栈大小



#include<pthread.h>
int pthread_attr_getstacksize(const pthread_attr_t *restrict attr,
	 size_t *restrict stacksize);
int pthread_attr_setstacksize(pthread_attr_t *attr,
	 size_t stacksize);


// 获取/设置线程的guardsize属性
#include<pthread.h>
int pthread_attr_getguardsize(const pthread_attr_t *restrict attr,
	 size_t *restrict guardsize);
int pthread_attr_setguardsize(pthread_attr_t *attr,
	 size_t guardsize);







