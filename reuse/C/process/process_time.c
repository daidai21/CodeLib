/* =============================================================================
> File Name: process_time.c
> Author: DaiDai
> Mail: daidai4269@aliyun.com
> Created Time: Tue 17 Sep 2019 09:10:34 PM CST
============================================================================= */


#include <stdio.h>
#include <sys/times.h>
#include <limits.h>


void run_some() {
  int j;
  for (int i = 0; i < INT_MAX; ++i)
    j *= i;
}


int main() {
  run_some();

  struct tms st_tms;
  if (times(&st_tms) < 0)
    printf("times exec error\n");
  else {
    printf("system CPU time, terminated child %ld\n", st_tms.tms_cstime);
    printf("user CPU time, terminated child   %ld\n", st_tms.tms_cutime);
    printf("system CPU time                   %ld\n", st_tms.tms_stime);
    printf("user CPU time                     %ld\n", st_tms.tms_utime);
  }

  return 0;
}
