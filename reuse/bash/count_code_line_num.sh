#!/usr/bin/env bash


# #############################################################################
# File Name   : count_code_line_num.sh
# Author      : DaiDai
# Mail        : daidai4269@aliyun.com
# Created Time: 日  9/13 15:16:15 2020
# #############################################################################


path=$1
if [ -z "$path" ]
then
    echo "ERROR: path param is NULL"
    exit 1
else
    echo "Path: " $path
fi


cpp_line_num=$(find $path -type f | grep -E "\.cpp|\.hpp|\.hh|\.cc|\.hxx" | xargs wc -l | awk '{print $1}' | awk 'END {print}' )
c_line_num=$(find $path -type f | grep -E "\.c|\.h" | xargs wc -l | awk '{print $1}' | awk 'END {print}' )
py_line_num=$(find $path -type f | grep "\.py" | xargs wc -l | awk '{print $1}' | awk 'END {print}' )
sh_line_num=$(find $path -type f | grep "\.sh" | xargs wc -l | awk '{print $1}' | awk 'END {print}' )
java_line_num=$(find $path -type f | grep "\.java" | xargs wc -l | awk '{print $1}' | awk 'END {print}' )


cpp_line_num=${cpp_line_num:-0}
c_line_num=${c_line_num:-0}
py_line_num=${py_line_num:-0}
sh_line_num=${sh_line_num:-0}
java_line_num=${java_line_num:-0}


echo "***** Code Total Result: *****"
echo "C++: $cpp_line_num"
echo "C: $c_line_num"
echo "Python: $py_line_num"
echo "Shell: $sh_line_num"
echo "Java: $java_line_num"
echo "Total: " $( expr  $cpp_line_num + \
                        $c_line_num + \
                        $py_line_num + \
                        $sh_line_num + \
                        $java_line_num)
