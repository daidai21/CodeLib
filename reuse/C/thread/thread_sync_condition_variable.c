/* =============================================================================
> File Name: thread_sync_condition_variable.c
> Author: DaiDai
> Mail: daidai4269@aliyun.com
> Created Time: Wed 11 Sep 2019 04:26:05 PM CST
============================================================================= */


#include <stdio.h>



// 条件变量

#include<pthread.h>
int pthread_cond_init(pthread_cond_t *restrict cond,
	const pthread_condattr_t *restrict attr);
int pthread_cond_destroy(pthread_cond_t *cond);

// 等待条件成立
#include<pthread.h>
#include<time.h>
int pthread_cond_wait(pthread_cond_t *restrict cond,
	pthread_mutext_t *restrict mutex);
int pthread_cond_timedwait(pthread_cond_t *restrict cond,
	pthread_mutext_t *restrict mutex,
	const struct timespect*restrict tsptr);



// 通知所有线程，某个条件成立

#include<pthread.h>
int pthread_cond_signal(pthread_cond_t *cond);
int pthread_cond_broadcast(pthread_cond_t *cond);
