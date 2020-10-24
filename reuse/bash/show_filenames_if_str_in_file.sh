#!/usr/bin/env bash


# #############################################################################
# File Name   : /Users/fwh/Documents/git-repo/self.lib/reuse/bash/show_filenames_if_str_in_file.sh
# Author      : DaiDai
# Mail        : daidai4269@aliyun.com
# Created Time: 三 10/21 15:53:12 2020
# #############################################################################


str=$1  # The string found in the file
line_num=0
for filename in `find . -name "*.java"`
do
    if [ `cat ${filename} | grep ${str} | wc -l` -gt 0 ]
    then
        tmp_line_num=`wc -l ${filename} | awk '{print $1}'`
        echo ${filename} $tmp_line_num
        line_num=`expr $line_num + $tmp_line_num`
    fi
done
echo $line_num
