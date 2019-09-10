#!/usr/bin/env python3
# -*- coding:utf-8 -*-


# =============================================================================
# File Name: thread_sync_share_memory.py
# Author: DaiDai
# Mail: daidai4269@aliyun.com
# Created Time: Tue 10 Sep 2019 10:04:02 PM CST
# =============================================================================


# TODO:


from typing import List
from threading import Thread


obj = []


class ThreadSharedMemory(object):
    def __init__(self, obj=None):
        self.__obj = obj
        self.__backup_obj = obj

    def __new__(self, *args, **kwargs):  # close inherit
        if self != ThreadSharedMemory:
            raise Exception("class {0} can't be inherit.".format("ThreadSharedMemory"))
        return super(ThreadSharedMemory, self).__new__(self, *args, **kwargs)

    def __repr__(self,):
        return "ThreadSharedMemory"

    def write(self, data):
        # TODO
        return

    def read(self):
        return self.__obj

    def name(self):
        return str(self.__class__.__name__)


if __name__ == "__main__":
    t = ThreadSharedMemory()
    print(t)
    print(t.name())
