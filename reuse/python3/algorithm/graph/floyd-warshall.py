#!/usr/bin/env python3
# -*- coding:utf-8 -*-



def floyd(graph):
    length = len(graph[0])
    for k in range(length):
        for i in range(length):
            for j in range(length):
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j])
    return graph


if __name__ == "__main__":
    graph = [
        [0, 2, 1, 4, 5, 1],
        [1, 0, 4, 2, 3, 4],
        [2, 1, 0, 1, 2, 4],
        [3, 5, 2, 0, 3, 3],
        [2, 4, 3, 4, 0, 1],
        [3, 4, 7, 3, 1, 0]
    ]
    print(floyd(graph))
