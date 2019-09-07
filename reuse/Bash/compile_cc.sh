#!/usr/bin/env bash

# =============================================================================
# File Name: compile_cc.sh
# Author: DaiDai
# Mail: daidai4269@aliyun.com
# Created Time: Fri 06 Sep 2019 08:56:39 PM CST
# =============================================================================


g++ std=c++11 $1
if [ $? -eq 0 ];
then
    ./a.out
fi
