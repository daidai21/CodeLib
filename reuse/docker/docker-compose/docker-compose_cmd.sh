#!/usr/bin/env bash


# #############################################################################
# File Name   : docker-compose_cmd.sh
# Author      : DaiDai
# Mail        : daidai4269@aliyun.com
# Created Time: 四  4/15 01:43:19 2021
# #############################################################################


# 查看版本
docker-compose --version


# 重启
sudo docker-compose restart


# 启动
sudo docker-compose start


# 创建容器编排
docker-compose up


# 后台创建容器编排
docker-compose up -d


# 停止服务
docker-compose stop


# 根据指定文件启动
docker-compose -f compose.yml up


# 列出所有容器
docker-compose ps


# 列出compose.yml定义的所有容器
docker-compose -f compose.yml ps


# 进入容器
# 登录到nginx容器中
docker-compose exec nginx bash


# 删除容器
# 删除所有（停止状态的）服务容器
docker-compose rm 


# 构建或者重新构建服务的image
docker-compose build


# 不带缓存的构建
docker-compose build --no-cache nginx


# 停用移除所有容器以及网络相关
docker-compose down


# 查看nginx的日志
docker-compose logs  nginx


# 拉取服务依赖的镜像
docker-compose pull


# 暂停nignx容器
docker-compose pause nginx


# 恢复ningx容器
docker-compose unpause nginx


# 设置指定服务运行的容器个数。通过 service=num 的参数来设置数量
docker-compose scale web=3 db=2


# 停止服务
docker-compose kill


# 列出所有镜像
docker-compose images


# push服务镜像
docker-compose push


# 显示各个容器内运行的进程
docker-compose top
