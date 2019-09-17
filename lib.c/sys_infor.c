/* =============================================================================
> File Name: sys_infor.c
> Author: DaiDai
> Mail: daidai4269@aliyun.com
> Created Time: Wed 04 Sep 2019 07:42:37 PM CST
============================================================================= */


/*
  sys information abaout version,
*/


#if unix
#include <unistd.h>  /* UNIX sys */
#elif win
#include <windows.h>  /* Win32 sys */
#endif

/*
  multiply OS
*/

#include <stddef.h>
size_t var;

int main() {}
