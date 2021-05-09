/* ****************************************************************************
 * File Name   : msg_que.h
 * Author      : DaiDai
 * Mail        : daidai4269@aliyun.com
 * Created Time: 日  5/ 2 23:51:58 2021
 *************************************************************************** */

#ifndef __MSG_QUE_H__
#define __MSG_QUE_H__

#include <stddef.h>

typedef struct __msg_que msg_que_t;

#ifdef __cplusplus
extern "C" {
#endif  // __cplusplus

msg_que_t* msg_que_create(size_t maxlen, int linkoff);
void msg_que_put(msg_que_t* que, void* msg);
void* msg_que_get(msg_que_t* que);
void msg_que_set_nonblock(msg_que_t* que);
void msg_que_set_block(msg_que_t* que);
void msg_que_destroy(msg_que_t* que);

#ifdef __cplusplus
}
#endif  // __cplusplus

#endif  // __MSG_QUE_H__
