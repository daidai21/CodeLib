#!/usr/bin/env bash

# =============================================================================
# File Name: compile.sh
# Author: DaiDai
# Mail: daidai4269@aliyun.com
# Created Time: Tue 15 Oct 2019 11:24:34 PM CST
# =============================================================================


# reachable is not Memory leak


echo "+++++ compile code +++++"
g++ -std=c++11 \
    Trie_test.cpp

echo "+++++ run code +++++"
./a.out | c++filt -t

echo "+++++ check code +++++"
valgrind --tool=memcheck --leak-check=full --show-leak-kinds=all ./a.out
