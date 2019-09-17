/* =============================================================================
> File Name: function_system.c
> Author: DaiDai
> Mail: daidai4269@aliyun.com
> Created Time: Tue 17 Sep 2019 06:09:24 PM CST
============================================================================= */


/*
  API
    int system(const char* cmdstring);
*/


#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>


int main() {
  system("ls -al /etc/passwd /etc/shadow");

  return 0;
}
