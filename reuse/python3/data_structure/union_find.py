#!/usr/bin/env python3
# -*- coding:utf-8 -*-

# #############################################################################
# File Name   : union_find.py
# Author      : DaiDai
# Mail        : daidai4269@aliyun.com
# Created Time: 日 10/25 23:36:43 2020
# #############################################################################


"""
并查集
并查集是一种树形的数据结构，顾名思义，它用于处理一些不交集的 合并 及 查询 问题。 它支持两种操作：

查找（Find）：确定某个元素处于哪个子集；
合并（Union）：将两个子集合并成一个集合。
"""


class UnionFind(object):
    def __init__(self, n):
        self.parent = list(range(n))

    def find(self, x):
        if self.parent[x] != x:
            self.parent[x] = self.find(self.parent[x])
        return self.parent[x]

    def union(self, x, y):
        x = self.find(x)
        y = self.find(y)
        if x == y:
            return
        self.parent[x] = y

    def cnt_root(self):
        return len(set([self.find(node) for node in self.parent]))

    def show(self):
        print(self.parent)

        father_son = {}
        for idx, son in enumerate(self.parent):
            father = self.find(son)
            if father == idx:
                continue
            if father in father_son:
                father_son[father].append(idx)
            else:
                father_son[father] = [idx]
        for father, son in father_son.items():
            print(father, ":", son)


if __name__ == '__main__':
    uf = UnionFind(10)
    print(uf.parent)

    print("uf.union()")
    uf.union(0, 1)
    uf.union(1, 3)
    uf.union(3, 6)
    uf.union(6, 7)
    uf.union(2, 9)
    uf.union(4, 8)
    uf.union(5, 8)

    print("uf.cnt_root()")
    print(uf.cnt_root())
    assert uf.cnt_root() == 3

    print("uf.find()")
    for i in range(10):
        print(str(i) + " -> " + str(uf.find(i)))

    print("uf.show()")
    uf.show()
