/* =============================================================================
> File Name: process_schedule.c
> Author: DaiDai
> Mail: daidai4269@aliyun.com
> Created Time: Tue 17 Sep 2019 09:02:23 PM CST
============================================================================= */


/*
  test only one example

  API
    #include <unistd.h>
    int nice(int incr);
    #include <sys/resource.h>
    int getpriority(int which, id_t who);
    int setpriority(int which, id_t who, int value);
*/


#include <stdio.h>
#include <sys/resource.h>


int main() {
  printf("current process nice value is %d\n", getpriority(PRIO_USER, 0));
  setpriority(PRIO_USER, 0, 0); // improve priority
  printf("current process nice value is %d\n", getpriority(PRIO_USER, 0));

  return 0;
}
