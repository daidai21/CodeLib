#!/usr/bin/env python3
# -*- coding:utf-8 -*-


def get_local_ip() -> str:
    import socket

    try:
        s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        s.connect(("8.8.8.8", 8))
        (addr, port) = s.getsockname()
        s.close()
        return addr
    except socket.error:
        return "127.0.0.1"


if __name__ == "__main__":
    print(get_local_ip())
