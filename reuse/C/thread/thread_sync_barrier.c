/* =============================================================================
> File Name: thread_sync_barrier.c
> Author: DaiDai
> Mail: daidai4269@aliyun.com
> Created Time: Wed 11 Sep 2019 04:22:27 PM CST
============================================================================= */


#include <stdio.h>



// 屏障


#include<pthread.h>
int pthread_barrier_init(pthread_barrier_t *restrict barrier,
	const pthread_barrierattr_t *restrict attr,
	int count);
int pthread_barrier_destroy(pthread_barrier_t *barrier);

// 线程到达屏障并等待其他线程也到达屏障

#include<pthread.h>
int pthread_barrier_wait(pthread_barrier_t * barrier);
