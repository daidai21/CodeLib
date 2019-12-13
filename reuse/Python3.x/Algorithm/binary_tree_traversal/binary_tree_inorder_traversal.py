#!/usr/bin/env python3
# -*- coding:utf-8 -*-


# =============================================================================
# File Name: binary_tree_inorder_traversal.py
# Author: DaiDai
# Mail: daidai4269@aliyun.com
# Created Time: Fri Dec 13 14:21:17 2019
# =============================================================================


def inorder_recursion(node):
    if not node:
        return 

    inorder_recursion(node.left)

    # opt val
    print(node.val)

    inorder_recursion(node.right)


def inorder_iteration(node):
    if not node:
        return 
    stack = []
    result = []
    while node or stack:
        while node:
            stack.append(node)
            node = node.left
        node = stack.pop()
        result.append(node.val)
        node = node.right
    return result
