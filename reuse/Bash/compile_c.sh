#!/usr/bin/env bash

# =============================================================================
# File Name: compile_c.sh
# Author: DaiDai
# Mail: daidai4269@aliyun.com
# Created Time: Fri 06 Sep 2019 08:56:24 PM CST
# =============================================================================


gcc $1
if [ $? -eq 0 ];
then
    ./a.out
fi
