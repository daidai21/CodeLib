/* =============================================================================
> File Name: jump.c
> Author: DaiDai
> Mail: daidai4269@aliyun.com
> Created Time: Mon 09 Sep 2019 03:56:46 PM CST
============================================================================= */


#include <stdio.h>

/* 函数setjmp和longjmp */

#include <setjmp.h>

int setjmp(jmp_buf environment);
void longjmp(jmp_buf environment, int value);

