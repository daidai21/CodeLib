#!/usr/bin/env python3
# -*- coding:utf-8 -*-


# =============================================================================
# File Name: dijkstra.py
# Author: DaiDai
# Mail: daidai4269@aliyun.com
# Created Time: Fri 22 Nov 2019 03:04:13 PM CST
# =============================================================================


"""
link: https://gist.github.com/kachayev/5990802
"""


from collections import defaultdict
from heapq import heappop
from heapq import heappush


def dijkstra(edges, start, end):
    graph = defaultdict(list)
    for l, r, dis in edges:
        graph[l].append((dis, r))

    q = [(0, start, [])]
    seen = set()
    min_dis = {
        start: 0
    }

    while q:
        (cost, v1, path) = heappop(q)
        if v1 not in seen:
            seen.add(v1)
            path = [v1] + path
            if v1 == end:
                return (cost, path)

        for dis, v2 in graph.get(v1, []):
            if v2 in seen:
                continue
            prev = min_dis.get(v2, None)
            next = cost + dis
            if prev is None or next < prev:
                min_dis[v2] = next
                heappush(q, (next, v2, path))
    return (float("inf"), [])


if __name__ == "__main__":
    edges = [
        ("A", "B", 7),
        ("A", "D", 5),
        ("B", "C", 8),
        ("B", "D", 9),
        ("B", "E", 7),
        ("C", "E", 5),
        ("D", "E", 15),
        ("D", "F", 6),
        ("E", "F", 8),
        ("E", "G", 9),
        ("F", "G", 11)
    ]
    print("A -> E: ", end="")
    print(dijkstra(edges, "A", "E"))
    print("F -> G: ", end="")
    print(dijkstra(edges, "F", "G"))
    print("A -> Z: ", end="")
    print(dijkstra(edges, "A", "Z"))
