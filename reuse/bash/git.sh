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
git clone --recurse-submodules -j8 git://github.com/foo/bar.git

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

# 查看git仓库的root路径
git rev-parse --show-toplevel

# 跳转到git仓库的root路径
cd $(git rev-parse --show-cdup)

# 查看git仓库都有谁commit过
git log --pretty=format:"%ce %ae" | sort | uniq -c 

# 查看xxx都修改或创建过哪些文件
git whatchanged --author="${AuthorName}" --name-only --oneline | grep ${FilePath} | sort | uniq -c

# 进入子模块目录，将子模块回滚到指定commit版本
git reset --hard ${commit-number}

# 查看commitId属于哪个分支
git branch -r --contains ${commit-number}

# 查找文件， 之前commit过，但是后来删了
# https://stackoverflow.com/questions/7203515/how-to-find-a-deleted-file-in-the-project-commit-history
git log --all --full-history -- "**/thefile.*"
