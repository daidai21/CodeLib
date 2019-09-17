/* =============================================================================
> File Name: thread_sync_attr_read_write_lock.c
> Author: DaiDai
> Mail: daidai4269@aliyun.com
> Created Time: Thu 12 Sep 2019 05:25:23 PM CST
============================================================================= */



// 初始化/销毁读写锁属性

#include<pthread.h>
int pthread_rwlockattr_init(pthread_rwlockattr_t *attr);
int pthread_rwlockattr_destroy(pthread_rwlockattr_t *attr);	



// 读写锁支持的唯一属性是进程共享属性。它与互斥量的进程共享属性是相同的。获取/设置这一属性的函数为：


#include<pthread.h>
int pthread_rwlockattr_getpshared(const pthread_rwlockattr_t * restrict attr,
	int *restrict pshared);
int pthread_rwlockattr_setpshared(pthread_rwlockattr_t *attr,
	int pshared);


