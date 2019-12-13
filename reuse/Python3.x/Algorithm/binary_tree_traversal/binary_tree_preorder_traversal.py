#!/usr/bin/env python3
# -*- coding:utf-8 -*-


# =============================================================================
# File Name: binary_tree_preorder_traversal.py
# Author: DaiDai
# Mail: daidai4269@aliyun.com
# Created Time: Fri Dec 13 14:21:17 2019
# =============================================================================


def preorder_recursion(node):
    if not node:
        return 

    # opt val
    print(node.val)

    preorder_recursion(node.left)
    preorder_recursion(node.right)


def preorder_iteration(node):
    result = []
    stack = []
    while node or stack:
        while node:
            result.append(node.val)
            stack.append(node)
            node = node.left
        if stack:
            tmp = stack.pop()
            node = tmp.right
    return result
