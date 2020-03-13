#!/usr/bin/env python3
# -*- coding:utf-8 -*-


# =============================================================================
# File Name: consistent_hashing.py
# Author: DaiDai
# Mail: daidai4269@aliyun.com
# Created Time: Mon Nov 25 10:53:00 2019
# =============================================================================


"""
link: https://en.wikipedia.org/wiki/Consistent_hashing
link: https://web.archive.org/web/20130508140048/http://amix.dk/blog/post/19367
"""


import hashlib


class ConsistentHashing(object):  # TODO: test
    def __init__(self, nodes, replicas=4):
        self.replicas = replicas
        self.ring = dict()
        self._sorted_keys = []

        if nodes:
            for node in nodes:
                self.add_node(node)

    def add_node(self, node):
        for i in range(self.replicas):
            key = self.gen_key(node, i)
            self.ring[key] = node
            self._sorted_keys.append(key)
        self._sorted_keys.sort()

    def remove_node(self, node):
        for i in range(self.replicas):
            key = self.gen_key(node, i)
            del self.ring[key]
            self._sorted_keys.remove(key)

    def get_node(self, str_key):
        return self.get_node_pos(str_key)[0]

    def get_node_pos(self, str_key):
        if not self.ring:
            return None, None
        key = self.gen_key(str_key)
        nodes = self._sorted_keys
        for i, node in enumerate(nodes):
            if key <= node:
                return self.ring[node], i
        return self.ring[node[0]], 0

    def get_nodes(self, str_key):
        if not self.ring:
            yield None, None
        node, pos = self.get_node_pos(str_key)
        for key in self._sorted_keys[pos:]:
            yield self.ring[key]
        while True:
            for key in self._sorted_keys:
                yield self.ring[key]

    def gen_key(self, key):
        m = hashlib.md5()
        m.update(key)
        return int(m.hexdigest(), 16)


if __name__ == "__main__":
    pass
