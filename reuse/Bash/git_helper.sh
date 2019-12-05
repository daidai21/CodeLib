#!/usr/bin/env bash

# =============================================================================
# File Name: git_helper.sh
# Author: DaiDai
# Mail: daidai4269@aliyun.com
# Created Time: Thu 05 Dec 2019 10:51:03 PM CST
# =============================================================================


set -x
set -e


git add .
git commit -m "$(git status -s)"
git push origin master

