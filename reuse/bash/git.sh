#!/usr/bin/env bash


# #############################################################################
# File Name   : git.sh
# Author      : DaiDai
# Mail        : daidai4269@aliyun.com
# Created Time: 一 12/ 7 00:37:51 2020
# #############################################################################


# 远程分支rename
git checkout ${old_branch_name}
git branch ${new_branch_name}
git push origin --delete ${old_branch_name}
git branch -d ${old_branch_name}


# 查看本地分支和远程分支的对应关系
git branch -vv

# 撤销本地上一次commit
git reset --soft HEAD^

# 撤销远程上一次commit
git reset --soft HEAD^
git push origin ${branch_name} --force

# 暂存当前更改
git stash

# 查看暂存列表
git stash list

# clone并拉取所有子仓库
# TODO

# 撤销更改，删除 修改或新增的代码
git checkout -- ${filename}


# 撤销本地当前所有修改
git checkout . && git clean -xdf


# 添加子模块
git submodule add git@github.com:daidai21/JavaFrameworkDemo.git ./reuse/java/src/main/java/com/JavaFrameworkDemo


# 删除子模块  参数为主仓亏的路径地址
git rm /Users/fwh/Documents/git-repo/self.lib/reuse/java/src/main/java/com/framework_tool_jar


# 。
git tag --list 

# .
git checkout ${tag_name}

# 查看当前所在的tag
git describe --tags

# 删除远程分支
git push origin --delete ${remote_branch_name}


# 删除本地分支
git branch -d ${local_branch_name} 

# 查看commit改动根据commit_id
git show ${commit_id}

# 查看某个commit_id修改了哪些文件
git show --name-only  --oneline ${commit_id}
