/* =============================================================================
> File Name: thread_sync_attr_mutex.c
> Author: DaiDai
> Mail: daidai4269@aliyun.com
> Created Time: Thu 12 Sep 2019 05:26:09 PM CST
============================================================================= */


// 初始化/销毁互斥量	属性
#include<pthread.h>
int pthread_mutexattr_init(pthread_mutexattr_t *attr);
int pthread_mutexattr_destroy(pthread_mutexattr_t *attr);



// 获取/设置互斥量的进程共享属性
#include<pthread.h>
int phtread_mutexattr_getpshared(const pthread_mutexattr_t *restrict attr,
	int *restrict pshared);
int pthread_mutexattr_setpshared(pthread_mutexattr_t * attr,
	int pshared);

// 获取/设置互斥量的健壮属性


#include<pthread.h>
int pthread_mutexattr_getrobust(const pthread_mutexattr_t *restrict attr,
	int *restrict robust);
int pthread_mutexattr_setrobust(pthread_mutexattr_t * attr,
	int robust);

// 互斥量的owner切换工作
#include<pthread.h>
int pthread_mutex_consistent(pthread_mutex_t *mutex);


// 获取/设置互斥量的类型属性

#include<pthread>
int pthread_mutexattr_gettype(const pthread_mutexattr_t *restrict attr,
	int *restrict type);
int pthread_mutexattr_settype(pthread_mutexattr_t * attr,
	int type);

