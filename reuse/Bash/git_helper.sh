#!/usr/bin/env bash

# =============================================================================
# File Name: git_helper.sh
# Author: DaiDai
# Mail: daidai4269@aliyun.com
# Created Time: Thu 05 Dec 2019 10:51:03 PM CST
# =============================================================================


:<<COMMENT
git push script
COMMENT
set -x
set -e


git add .
git commit -m "$(git status -s)"
git push origin master


:<<COMMENT
git push script
COMMENT
git diff HEAD --no-ext-diff --unified=0 --exit-code -a --no-prefix | egrep "^\+" | wc.exe -m
