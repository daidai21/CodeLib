#!/usr/bin/env bash

# =============================================================================
# File Name: update.sh
# Author: DaiDai
# Mail: daidai4269@aliyun.com
# Created Time: Thu 22 Aug 2019 12:06:27 PM CST
# =============================================================================


# git update script
if [ "$1" -a "$2" ];
then
    git add $1
    git commit -m "update $1 $2"
    git push origin master
else
    echo "Error: need input two param"
    echo "the first  param:  file name or path"
    echo "the second param:  text of commit"
fi
