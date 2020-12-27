#!/usr/bin/env bash


# #############################################################################
# File Name   : maven.sh
# Author      : DaiDai
# Mail        : daidai4269@aliyun.com
# Created Time: 四 12/10 19:33:02 2020
# #############################################################################


# 创建新项目
# DgroupId   路径
# DartifactId   文件名
mvn archetype:generate -DgroupId=com.mycompany.app -DartifactId=my-app -DarchetypeArtifactId=maven-archetype-quickstart -DarchetypeVersion=1.4 -DinteractiveMode=false


# mvn package skip test
mvn package -Dmaven.test.skip=true 


# mvn install skip test
mvn install -Dmaven.test.skip=true 

# 检车代码规范
mvn checkstyle:check
