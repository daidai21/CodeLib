/* =============================================================================
> File Name: thread_sync_spin_lock.c
> Author: DaiDai
> Mail: daidai4269@aliyun.com
> Created Time: Wed 11 Sep 2019 04:25:21 PM CST
============================================================================= */


#include <stdio.h>



// 自旋锁
#include<pthread.h>
int pthread_spin_init(pthread_spinlock_t *restrict lock,
	int pshared);
int pthread_spin_destroy(pthread_spinlock_t *lock);



// 对自旋锁加锁/解锁操作


#include<pthread.h>
int pthread_spin_lock(pthread_spinlock_t *lock);
int pthread_spin_trylock(pthread_spinlock_t *lock);
int pthread_spin_unlock(pthread_spinlock_t *lock);

