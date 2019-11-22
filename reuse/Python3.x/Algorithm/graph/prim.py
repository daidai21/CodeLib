#!/usr/bin/env python3
# -*- coding:utf-8 -*-


# =============================================================================
# File Name: prim.py
# Author: DaiDai
# Mail: daidai4269@aliyun.com
# Created Time: Fri 22 Nov 2019 04:44:26 PM CST
# =============================================================================


def prim(graph, start):
    nodes = list(graph)
    nodes.remove(start)
    seen = [start]
    tree = []
    next = None
    while nodes:
        dis = float("inf")
        for start in seen:
            for end in graph[start]:
                if end in seen or start == end:
                    continue
                if graph[start][end] < dis:
                    dis = graph[start][end]
                    pre = start
                    next = end
        tree.append((pre, next))
        seen.append(next)
        nodes.remove(next)
    return tree


if __name__ == "__main__":
    graph = {
        "s1": {
            "s1": 0,
            "s2": 6,
            "s10": 3,
            "s12": 4,
            "s5": 3
        },
        "s2": {
            "s1": 1,
            "s2": 0,
            "s10": 4,
            "s12": 3,
            "s5": 4
        },
        "s10": {
            "s1": 2,
            "s2": 6,
            "s10": 0,
            "s12": 3,
            "s5": 4
        },
        "s12": {
            "s1": 1,
            "s2": 5,
            "s10": 2,
            "s12": 0,
            "s5": 2
        },
        "s5": {
            "s1": 3,
            "s2": 5,
            "s10": 7,
            "s12": 4,
            "s5": 0
        },
    }
    print(prim(graph, "s12"))
