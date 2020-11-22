#!/usr/bin/env bash


# #############################################################################
# File Name   : echo_color.sh
# Author      : DaiDai
# Mail        : daidai4269@aliyun.com
# Created Time: 五 11/20 16:48:37 2020
# #############################################################################


NOCOLOR='\033[0m'
RED='\033[0;31m'
GREEN='\033[0;32m'
ORANGE='\033[0;33m'
BLUE='\033[0;34m'
PURPLE='\033[0;35m'
CYAN='\033[0;36m'
LIGHTGRAY='\033[0;37m'
DARKGRAY='\033[1;30m'
LIGHTRED='\033[1;31m'
LIGHTGREEN='\033[1;32m'
YELLOW='\033[1;33m'
LIGHTBLUE='\033[1;34m'
LIGHTPURPLE='\033[1;35m'
LIGHTCYAN='\033[1;36m'
WHITE='\033[1;37m'

echo -e "The first five colors of the rainbow are ${RED}red ${ORANGE}orange ${YELLOW}yellow ${GREEN}green ${NOCOLOR}and ${BLUE}blue${NOCOLOR}"
