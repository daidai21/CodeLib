#!/usr/bin/env bash


# #############################################################################
# File Name   : judge_env_docker_or_read.sh
# Author      : DaiDai
# Mail        : daidai4269@aliyun.com
# Created Time: 四  4/29 14:15:53 2021
# #############################################################################


set -ex


if [ -f /.dockerenv ]; then
    echo "In Docker container.";
else
    echo "Not in Docker container.";
fi
