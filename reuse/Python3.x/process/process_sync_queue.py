#!/usr/bin/env python3
# -*- coding:utf-8 -*-


# =============================================================================
# File Name: process_sync_queue.py
# Author: DaiDai
# Mail: daidai4269@aliyun.com
# Created Time: Wed 11 Sep 2019 08:31:54 PM CST
# =============================================================================


from multiprocessing import Process
from multiprocessing import Queue
import random


def job(q):
    q.put(random.random())


def multi_process():
    q = Queue()
    p1 = Process(target=job, args=(q, ))
    p2 = Process(target=job, args=(q, ))
    p1.start()
    p2.start()
    p1.join()
    p2.join()
    print(q.get(), q.get())


if __name__ == "__main__":
    multi_process()
