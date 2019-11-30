/* =============================================================================
> File Name: thread_pool.h
> Author: DaiDai
> Mail: daidai4269@aliyun.com
> Created Time: Fri 29 Nov 2019 03:28:00 PM CST
============================================================================= */


#ifndef THREAD_POOL_H_
#define THREAD_POOL_H_


#ifdef __cplusplus
extern "C" {
#endif // __cplusplus


struct thread_pool_t;
typedef struct thread_pool_t* thread_pool_p;

thread_pool_p thread_pool_init(unsigned int num_threads);
int thread_pool_add_work(thread_pool_p tp_p, void (* func)(void* ), void* arg_p); // FIXME: arg_p
void thread_pool_wait(thread_pool_p tp_p);
void thread_pool_destroy(thread_pool_p tp_p);
void thread_pool_puse(thread_pool_p tp_p);
void thread_pool_resume(thread_pool_p tp_p);
unsigned int thread_pool_num_threads_working(thread_pool_p tp_p);


#ifdef __cplusplus
}
#endif // __cplusplus


#endif // THREAD_POOL_H_
