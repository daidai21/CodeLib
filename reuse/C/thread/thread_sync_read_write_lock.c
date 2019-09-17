/* =============================================================================
> File Name: thread_sync_read_write_lock.c
> Author: DaiDai
> Mail: daidai4269@aliyun.com
> Created Time: Wed 11 Sep 2019 04:24:41 PM CST
============================================================================= */


#include <stdio.h>



// 读写锁
#include<pthread.h>
int pthread_rwlock_init(pthread_rwlock_t *restrict rwlock,
	const pthread_rwlockattr_t *restrict attr);
int pthread_rwlock_destroy(pthread_rwlock_t *rwlock);


// 对读写锁加锁/解锁操作

#include<pthread.h>
int pthread_rwlock_rdlock(pthread_rwlock_t *rwlock);
int pthread_rwlock_wrlock(pthread_rwlock_t *rwlock);
int pthread_rwlock_unlock(pthread_rwlock_t *rwlock);


// 对读写锁加锁的条件版本
#include<pthread.h>
int pthread_rwlock_tryrdlock(pthread_rwlock_t *rwlock);
int pthread_rwlock_trywrlock(pthread_rwlock_t *rwlock);

// 对读写锁加锁的超时版本

#include<pthread.h>
#include<time.h>
int pthread_rwlock_timedrdlock(pthread_rwlock_t *rwlock,
	const struct timespect*restrict tsptr);
int pthread_rwlock_timedwrlock(pthread_rwlock_t *rwlock,
	const struct timespect*restrict tsptr);
