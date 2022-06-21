#!/usr/bin/env bash


# #############################################################################
# File Name   : text.sh
# Author      : DaiDai
# Mail        : daidai4269@aliyun.com
# Created Time: 四 12/10 11:06:02 2020
# #############################################################################

# awk sed grep


# 删除a.txt中含"abc"的行，但不改变a.txt文件本身，操作之后的结果在终端显示
sed -e '/abc/d'  a.txt


# 查看 72200 ~ 72250 行
sed -n '72200, 72250p' ecom.activity.biz_mesh_service.run.log.2022-06-21
