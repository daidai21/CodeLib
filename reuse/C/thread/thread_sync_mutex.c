/* =============================================================================
> File Name: thread_sync_mutex.c
> Author: DaiDai
> Mail: daidai4269@aliyun.com
> Created Time: Wed 11 Sep 2019 04:23:29 PM CST
============================================================================= */


#include <stdio.h>


// 互斥量
#include<pthread.h>
int pthread_mutex_init(pthread_mutex_t *restrict mutex,
	const pthread_mutexattr_t *restrict attr);
int pthread_mutex_destroy(pthread_mutex_t *mutex);


// 对互斥量加锁/解锁操作

#include<pthread.h>
int pthread_mutex_lock(pthread_mutex_t *mutex);
int pthread_mutex_trylock(pthread_mutex_t *mutex);
int pthread_mutex_unlock(pthread_mutex_t *mutex);


// 对互斥量加锁或等待指定时间

#include<pthread.h>
#include<time.h>
int pthread_mutex_timedlock(pthread_mutex_t *restrict mutex,
	const struct timespec *restrict tsptr);
