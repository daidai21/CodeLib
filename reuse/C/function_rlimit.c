/* =============================================================================
> File Name: function_rlimit.c
> Author: DaiDai
> Mail: daidai4269@aliyun.com
> Created Time: Mon 16 Sep 2019 07:56:44 PM CST
============================================================================= */


/*
  process resource limit
*/


#include <stdio.h>
#include<sys/resource.h>


void print_current_sys_rlimit() {
  // output part rlimit, not all

  struct rlimit limit;
  printf("current process resource limit: \n");

  getrlimit(RLIMIT_AS, &limit);
  printf("RLIMIT_AS %ld %ld\n", limit.rlim_cur, limit.rlim_max);
  getrlimit(RLIMIT_CORE, &limit);
  printf("RLIMIT_CORE %ld %ld\n", limit.rlim_cur, limit.rlim_max);
  getrlimit(RLIMIT_CPU, &limit);
  printf("RLIMIT_CPU %ld %ld\n", limit.rlim_cur, limit.rlim_max);
  getrlimit(RLIMIT_DATA, &limit);
  printf("RLIMIT_DATA %ld %ld\n", limit.rlim_cur, limit.rlim_max);
  getrlimit(RLIMIT_FSIZE, &limit);
  printf("RLIMIT_FSIZE %ld %ld\n", limit.rlim_cur, limit.rlim_max);
  getrlimit(RLIMIT_MEMLOCK, &limit);
  printf("RLIMIT_MEMLOCK %ld %ld\n", limit.rlim_cur, limit.rlim_max);
  getrlimit(RLIMIT_MSGQUEUE, &limit);
  printf("RLIMIT_MSGQUEUE %ld %ld\n", limit.rlim_cur, limit.rlim_max);
  getrlimit(RLIMIT_NICE, &limit);
  printf("RLIMIT_NICE %ld %ld\n", limit.rlim_cur, limit.rlim_max);
}

void reset_rlimit() {
  printf("reset rlimit: \n");
  struct rlimit limit;
  getrlimit(RLIMIT_MSGQUEUE, &limit);
  printf("RLIMIT_MSGQUEUE %ld %ld\n", limit.rlim_cur, limit.rlim_max);

  limit.rlim_cur = 123;
  limit.rlim_max = 123;
  setrlimit(RLIMIT_MSGQUEUE, &limit);

  getrlimit(RLIMIT_MSGQUEUE, &limit);
  printf("RLIMIT_MSGQUEUE %ld %ld\n", limit.rlim_cur, limit.rlim_max);
}

int main() {
  print_current_sys_rlimit();

  reset_rlimit();

  return 0;
}
