/* =============================================================================
> File Name: envuronmen_variable.c
> Author: DaiDai
> Mail: daidai4269@aliyun.com
> Created Time: Mon 09 Sep 2019 03:54:23 PM CST
============================================================================= */


#include <stdio.h>
#include <stdlib.h>


char *getenv(const char *name);

int putenv(char *str);
int setenv(const char *name, const char *value, int rewrite);
int unsetenv(const char *name);
