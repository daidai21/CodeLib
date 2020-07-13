#!/usr/bin/env bash


# #############################################################################
# File Name   : find_port_number_by_process_name.sh
# Author      : DaiDai
# Mail        : daidai4269@aliyun.com
# Created Time: 一  7/13 11:10:45 2020
# #############################################################################


echo "param: [process name]"
echo "InputParam: " $1
process_name=$1
if [ `uname -s` == "Darwin" ]; # MacOS
then
    :
    echo "OS: MacOS"
    # process name -> pids
    # TODO
    pids=`ps aux | grep $process_name | awk '{print $2}'`
    echo $pids
    # pid -> port
    echo "process_name | pid | port"
    for pid in $pids
    do
        :
        tmp_result=`lsof -i | grep $pid`
        if [ `echo $tmp_result | wc -l` == 0 ] # pid have not port
        then
            :
        else
            :
            echo `tmp_result | awk '{print $9 | $2 | PORT }'` # TODO: PORT err
        fi
    done
    # TODO
elif [ `uname -s` == "Linux" ] # linux
then
    :
    echo "OS: Linux"
    # TODO: ps -aux
fi

