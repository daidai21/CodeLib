/* ****************************************************************************
 * File Name   : msg_que_example.c
 * Author      : DaiDai
 * Mail        : daidai4269@aliyun.com
 * Created Time: 一  5/ 3 00:56:32 2021
 *************************************************************************** */


#include <stdio.h>
#include "./msg_que.h"

int main(int argc, char* argv[]) {
  msg_que_t* tmp_mq = msg_que_create(10, sizeof(void*));
  char str[] = "hello";
  msg_que_put(tmp_mq, str);
  char* p = msg_que_get(tmp_mq);
  printf("%s\n", p);

  return 0;
}

