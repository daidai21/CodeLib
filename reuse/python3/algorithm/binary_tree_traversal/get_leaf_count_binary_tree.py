#!/usr/bin/env python3
# -*- coding:utf-8 -*-


# #############################################################################
# File Name   : get_leaf_count_binary_tree.py
# Author      : DaiDai
# Mail        : daidai4269@aliyun.com
# Created Time: 五  9/11 01:30:03 2020
# #############################################################################


# TODO
# not test


from binary_tree_node import BinaryTreeNode


def get_leaf_count_binary_tree(node: BinaryTreeNode) -> int:
    count = 0
    if node is not None:
        if node.left is None and node.right is None:
            count += 1
        count += get_leaf_count_binary_tree(node.left)
        count += get_leaf_count_binary_tree(node.right)
    return count
