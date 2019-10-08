#!/usr/bin/env bash

# =============================================================================
# File Name: judge_operator_system_version.sh
# Author: DaiDai
# Mail: daidai4269@aliyun.com
# Created Time: Wed 18 Sep 2019 06:45:55 PM CST
# =============================================================================


# TODO: have not in mac, centos and FreeBSD test


if [ `uname -s` = "Linux" ];
then
    echo "Linux"
    if [[ `uname -a` =~ "Darwin" ]];
    then
        echo "Mac OX"
    elif [[ `uname -a` =~ "ubuntu" ]];
    then
        echo "Ubuntu"
    elif [[ `uname -a` =~ "centos" ]];
    then
        echo "Centos"
    else
        echo "ERROR: not find this OS version"
    fi
elif [ `uname -s` = "FreeBSD" ];
then
    echo "FreeBSD" 
else
    echo "ERROR: not find this OS version"
fi
