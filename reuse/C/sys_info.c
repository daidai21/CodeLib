/* =============================================================================
> File Name: sys_info.c
> Author: DaiDai
> Mail: daidai4269@aliyun.com
> Created Time: Sun 15 Sep 2019 10:00:57 PM CST
============================================================================= */


#include <stdio.h>
#include <sys/sysinfo.h>


int main() {
  printf("cpu total: %d\n", get_nprocs_conf());
  printf("current can use cpu num: %d\n", get_nprocs());

  return 0;
}
