/* =============================================================================
> File Name: user_mark.c
> Author: DaiDai
> Mail: daidai4269@aliyun.com
> Created Time: Tue 17 Sep 2019 08:59:45 PM CST
============================================================================= */


#include <stdio.h>
#include <unistd.h>


int main() {
  printf("%s\n", getlogin());
  return 0;
}
