#!/usr/bin/env bash


# #############################################################################
# File Name   : run.sh
# Author      : DaiDai
# Mail        : daidai4269@aliyun.com
# Created Time: 三  4/14 16:51:45 2021
# #############################################################################

mvn package
mvn compile

echo "Java Call Scala:"
java -classpath target/java_scala_mixture-1.0-SNAPSHOT.jar:/usr/local/Cellar/scala/2.13.5/libexec/lib/scala-library.jar com.example.demo.CallScala


echo "Scala Call Java:"
# BUG: cmd run error, idea run ok
java -classpath target/java_scala_mixture-1.0-SNAPSHOT.jar:/usr/local/Cellar/scala/2.13.5/libexec/lib/scala-library.jar com.example.demo.CallJava
