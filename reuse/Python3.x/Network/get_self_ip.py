#!/usr/bin/env python3
# -*- coding:utf-8 -*-


# =============================================================================
# File Name: get_self_ip.py
# Author: DaiDai
# Mail: daidai4269@aliyun.com
# Created Time: Fri 22 Nov 2019 05:00:45 PM CST
# =============================================================================


import socket


def get_self_ip():
    try:
        s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        s.connect(("8.8.8.8", 8))
        (addr, port) = s.getsockname()
        s.close()
        return addr
    except socket.error:
        return "127.0.0.1"


if __name__ == "__main__":
    print(get_self_ip())
