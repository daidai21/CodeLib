/* =============================================================================
> File Name: process_account.c
> Author: DaiDai
> Mail: daidai4269@aliyun.com
> Created Time: Tue 17 Sep 2019 08:51:10 PM CST
============================================================================= */


#include <stdio.h>
#include <sys/acct.h>


int main() {
  struct acct acdata;

  printf("ac_flag  %d\n", acdata.ac_flag);
  printf("ac_uid   %d\n", acdata.ac_uid);
  printf("ac_gid   %d\n", acdata.ac_gid);
  printf("ac_tty   %d\n", acdata.ac_tty);
  printf("ac_btime %d\n", acdata.ac_btime);
  printf("ac_utime %d\n", acdata.ac_utime);
  printf("ac_etime %d\n", acdata.ac_etime);
  printf("ac_mem   %d\n", acdata.ac_mem);
  printf("ac_io    %d\n", acdata.ac_io);
  printf("ac_rw    %d\n", acdata.ac_rw);

  return 0;
}
