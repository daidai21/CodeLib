/* =============================================================================
> File Name: thread_sync_attr_barrier.c
> Author: DaiDai
> Mail: daidai4269@aliyun.com
> Created Time: Thu 12 Sep 2019 05:24:28 PM CST
============================================================================= */


#include <stdio.h>

初始化/销毁屏障属性


#include<pthread.h>
int pthread_barrierattr_init(pthread_barrierattr_t *attr);
int pthread_barrierattr_destroy(pthread_barrierattr_t *attr);	



// 屏障支持的唯一属性是进程共享属性。它与互斥量的进程共享属性是相同的。获取/设置这一属性的函数为：

#include<pthread.h>
int pthread_barrierattr_getpshared(const pthread_barrierattr_t * restrict attr,
	int *restrict pshared);
int pthread_barrierattr_setpshared(pthread_barrierattr_t *attr,
	int pshared);



  