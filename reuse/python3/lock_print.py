#!/usr/bin/env python3
# -*- coding:utf-8 -*-


# #############################################################################
# File Name   : lock_print.py
# Author      : DaiDai
# Mail        : daidai4269@aliyun.com
# Created Time: 三  3/24 14:42:42 2021
# #############################################################################


"""
Bram Cohen lprint
https://stackoverflow.com/questions/40356200/python-printing-in-multiple-threads
https://bramcohen.livejournal.com/70686.html
"""


from threading import Lock
from concurrent.futures import ThreadPoolExecutor

g_print_lock = Lock()

def lprint(*a, **b):
    """Thread safe print function"""
    with g_print_lock:
        print(*a, **b)


if __name__ == '__main__':
    # single thread test
    lprint(1,32)
    lprint("asd", 32)
    for i in range(10):
        lprint("asd", i)

    # multi thread test
    executor = ThreadPoolExecutor(max_workers=10)
    for _ in range(50):
        executor.submit(lambda: print("asd"))
