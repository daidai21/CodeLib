#!/usr/bin/env python3
# -*- coding:utf-8 -*-

# #############################################################################
# File Name   : captured_yield_example.py
# Author      : DaiDai
# Mail        : daidai4269@aliyun.com
# Created Time: 三  3/31 17:23:42 2021
# #############################################################################


def print_name(prefix):
    print("Searching prefix: {}".format(prefix))
    try:
        while True:
            name = (yield)
            if prefix in name:
                print(name)
    except GeneratorExit:
        print("Closing coroutine!!")

if __name__ == '__main__':
    corou = print_name("Dear")
    corou.__next__()

    corou.send("Atul")
    corou.send("Dear Atul")
    corou.close()
    try:
        corou.send("Dear Atul")
    except:
        print("Error: corou already closed")
