/* =============================================================================
> File Name: coroutine.h
> Author: DaiDai
> Mail: daidai4269@aliyun.com
> Created Time: Thu 21 Nov 2019 05:37:56 PM CST
============================================================================= */


#ifndef COROUTINE_H_
#define COROUTINE_H_


#define COROUTINE_STATUS_DEAD    0
#define COROUTINE_STATUS_READY   1
#define COROUTINE_STATUS_RUNNING 2
#define COROUTINE_STATUS_SUSPEND 3


struct Schedule;

typedef void (*coroutine_func)(struct Schedule* , void* ud); // FIXME && TODO

struct Schedule* coroutine_open(void);
void coroutine_close(struct Schedule*);

int coroutine_new(struct Schedule* , coroutine_func, void* ud);
void coroutine_resume(struct Schedule* , int id);
int coroutine_status(struct Schedule* , int id);
int coroutine_running(struct Schedule* );
void coroutine_yield(struct Schedule* );


#endif // COROUTINE_H_

