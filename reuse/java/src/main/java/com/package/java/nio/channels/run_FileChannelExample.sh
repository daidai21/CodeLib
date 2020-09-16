#!/usr/bin/env bash


# #############################################################################
# File Name   : run_FileChannelExample.sh
# Author      : DaiDai
# Mail        : daidai4269@aliyun.com
# Created Time: 三  9/16 17:57:56 2020
# #############################################################################


mkfile -n 1g read_big_file.dat
mkfile -n 1g write_big_file.dat

javac FileChannelExample.java
echo "*** zeroCopy ***"
time java FileChannelExample ./read_big_file.dat ./write_big_file.dat zeroCopy

echo "*** copy ***"
time java FileChannelExample ./read_big_file.dat ./write_big_file.dat copy

rm read_big_file.dat
rm write_big_file.dat
