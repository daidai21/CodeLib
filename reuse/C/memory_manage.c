/* =============================================================================
> File Name: memory_manage.c
> Author: DaiDai
> Mail: daidai4269@aliyun.com
> Created Time: Mon 09 Sep 2019 03:54:52 PM CST
============================================================================= */


#include <stdio.h>

/* 存储空间分配 */


#include <stdlib.h>


void *malloc(size_t size);
void *calloc(size_t nobj, size_t size);
void *realloc(void *ptr, size_t newsize);

void free(void *ptr);
