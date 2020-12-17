#!/usr/bin/env bash


# #############################################################################
# File Name   : JVM.sh
# Author      : DaiDai
# Mail        : daidai4269@aliyun.com
# Created Time: 一 12/14 14:50:58 2020
# #############################################################################


# Java Virtual Machine Process Status Tool
# 显示当前所有java进程pid
jps
jps -l  # 输出完全的包名，应用主类名，jar的完全路径名 
jps -v  # 输出jvm参数
jps -mlv


# 堆栈跟踪工具 堆栈信息
jstack

# jmap命令是一个可以输出所有内存中对象的工具，甚至可以将VM 中的heap，以二进制输出成文本。
# 打印出某个java进程（使用pid）内存内的，所有‘对象’的情况（如：产生那些对象，及其数量）。
jmap

# 打印出某个java进程（使用pid）内存内的，所有‘对象’的情况（如：产生那些对象，及其数量）。
jhat


# Java Virtual Machine statistics monitoring tool
# 用于见识虚拟机各种运行状态信息的命令行工具
jstat

# Java Configuration Info
# 主要作用是实时查看和调整JVM配置参数
jinfo

# 内置Java性能分析器，可以从命令行或在GUI shell中运行
jconsole
