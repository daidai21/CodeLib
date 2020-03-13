#!/usr/bin/env python3
# -*- coding:utf-8 -*-


# =============================================================================
# File Name: limit_memory_cpu.py
# Author: DaiDai
# Mail: daidai4269@aliyun.com
# Created Time: Sat Aug 24 12:26:34 2019
# =============================================================================


import signal
import resource


__call__ = [
    "set_max_runtime",
    "set_max_memory",
]


def time_exceeded(signo, frame):
    print("Time's up!")
    raise SystemExit(1)


def set_max_runtime(seconds: int) -> None:
    soft, hard = resource.getrlimit(resource.RLIMIT_CPU)
    resource.setrlimit(resource.RLIMIT_CPU, (seconds, hard))
    signal.signal(signal.SIGXCPU, time_exceeded)


def set_max_memory(maxsize):
    soft, hard = resource.getrlimit(resource.RLIMIT_AS)
    resource.setrlimit(resource.RLIMIT_AS, (maxsize, hard))


if __name__ == '__main__':
    set_max_runtime(15)
