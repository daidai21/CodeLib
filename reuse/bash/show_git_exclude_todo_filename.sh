#!/usr/bin/env bash


# #############################################################################
# File Name   : show_git_exclude_todo_filename.sh
# Author      : DaiDai
# Mail        : daidai4269@aliyun.com
# Created Time: 一  7/13 00:57:45 2020
# #############################################################################


pwd
filenames=`ls | grep java`
for filename in $filenames
do
    todo_num=`cat $filename | grep TODO | wc -l`
    if [[ $todo_num -ge 1 ]]
    then
        :
        echo $todo_num $filename
    else
        :
        echo $filename
    fi
done
