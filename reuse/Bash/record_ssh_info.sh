#!/usr/bin/env bash

# =============================================================================
# File Name: record_ssh_info.sh
# Author: DaiDai
# Mail: daidai4269@aliyun.com
# Created Time: Wed 11 Sep 2019 05:02:36 PM CST
# =============================================================================


:<<'COMMENT'
    the var `ssh_list` record ssh infor (include username and ip)

    Example:
        $ ./record_ssh_info.sh 0
        run cmd: ssh root@0.0.0.0
        root@0.0.0.0's password: 
COMMENT


ssh_list=(
    "root@0.0.0.0"
)


cmd="ssh "${ssh_list[$1]}
echo "run cmd: "$cmd
$cmd
