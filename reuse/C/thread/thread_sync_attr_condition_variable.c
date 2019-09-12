/* =============================================================================
> File Name: thread_sync_attr_condition_variable.c
> Author: DaiDai
> Mail: daidai4269@aliyun.com
> Created Time: Thu 12 Sep 2019 05:22:58 PM CST
============================================================================= */



// 初始化/销毁条件变量属性
#include<pthread.h>
int pthread_condattr_init(pthread_condattr_t *attr);
int pthread_condattr_destroy(pthread_condattr_t *attr);	


// 获取/设置条件变量的进程共享属性

#include<pthread.h>
int pthread_condattr_getpshared(const pthread_condattr_t * restrict attr,
	int *restrict pshared);
int pthread_condattr_setpshared(pthread_condattr_t *attr,
	int pshared);


// 获取/设置条件变量的时钟属性：
#include<pthread.h>
int pthread_condattr_getclock(const pthread_condattr_t * restrict attr,
	int *restrict clock_id);
int pthread_condattr_setclock(pthread_condattr_t *attr,
	int clock_id);


