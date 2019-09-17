/* =============================================================================
> File Name: thread.c
> Author: DaiDai
> Mail: daidai4269@aliyun.com
> Created Time: Mon 09 Sep 2019 10:21:09 PM CST
============================================================================= */

// 判断两个线程ID是否相等
#include <pthread.h>
int pthread_equal(pthread_t tid1, pthread tid2);


// 返回本线程自身的线程ID
#include <pthread.h>
pthread_t pthread_self(void);

// 创建新线程

#include <pthread.h>
int pthread_create(pthread_t *restrict tidp,
	const pthread_attr_t *restrict attr,
	void *(*start_rtn)(void*),
	void *restrict arg);

// 线程主动退出
#include <pthread.h>
void pthread_exit(void *rval_ptr);


// 等待指定的线程结束（类似于waitpid）
#include <pthread.h>
int pthread_join(pthread_t tid,void **rval_pptr);


// 请求取消同一个进程中的其他某个线程

#include <pthread.h>
int pthread_cancel(pthread_t tid);



// 注册与注销清理处理程序

#include <pthread.h>
void pthread_cleanup_push(void (*rtn)(void*),void *arg);
void pthread_cleanup_pop(int execute);

// 将指定线程设置为分离状态
#include<pthread.h>
int pthread_detach(pthread_t tid);

