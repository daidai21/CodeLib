#!/usr/bin/env python3
# -*- coding:utf-8 -*-


# =============================================================================
# File Name: thread_sync_timer.py
# Author: DaiDai
# Mail: daidai4269@aliyun.com
# Created Time: Tue 10 Sep 2019 03:16:13 PM CST
# =============================================================================


"""
using thread for glob_var add 1, 2 and 3 in turn, test whether threads run
 sequentially. thread sync using Timer (Timer instatiate is create new thread),
 result is true (but this is not absolutely correct).
URL: https://docs.python.org/zh-cn/3/library/threading.html
"""


from threading import Timer
import time


glob_var = []


def func1():
    glob_var.append(1)


def func2():
    glob_var.append(2)


def func3():
    glob_var.append(3)


def using_multiply_thread(start_times):
    print(glob_var)

    # create thread
    times = (
        Timer(interval=start_times[0], function=func1),
        Timer(interval=start_times[1], function=func2),
        Timer(interval=start_times[2], function=func3),
    )

    # start sub_thread
    for t in times:
        t.start()

    time.sleep(max(start_times) + 1)  # FIXME: join
    print(glob_var)


if __name__ == "__main__":
    using_multiply_thread([0.1, 0.2, 0.3])
    using_multiply_thread([0.3, 0.2, 0.1])
