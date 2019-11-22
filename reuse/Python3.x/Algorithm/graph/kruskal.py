#!/usr/bin/env python3
# -*- coding:utf-8 -*-

# =============================================================================
# File Name: kruskal.py
# Author: DaiDai
# Mail: daidai4269@aliyun.com
# Created Time: Fri 22 Nov 2019 04:35:51 PM CST
# =============================================================================


"""
link: https://github.com/muzixing/graph_algorithm/blob/master/kruskal.py
"""


def kruskal(graph):
    nodes = graph.keys()
    seen = set()
    tree = []
    next = None
    while len(seen) < len(nodes):
        dis = float("inf")
        for start in nodes:
            for end in nodes:
                if (start in seen and end in seen) or start == end:
                    continue
                if graph[start][end] < dis:
                    dis = graph[start][end]
                    pre = start
                    next = end
        tree.append((pre, next))
        seen.add(pre)
        seen.add(next)
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
    print(kruskal(graph))
