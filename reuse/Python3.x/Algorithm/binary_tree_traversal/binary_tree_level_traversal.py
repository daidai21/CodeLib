#!/usr/bin/env python3
# -*- coding:utf-8 -*-


# =============================================================================
# File Name: binary_tree_level_traversal.py
# Author: DaiDai
# Mail: daidai4269@aliyun.com
# Created Time: Fri Dec 13 14:21:17 2019
# =============================================================================


def level_traversal(node):
    if not node:
        return 
    result = []
    layer = [node]
    while layer:
        next_layer = []
        cur_layer_val = []
        node = result.pop(0)
        cur_layer_val.append(node.val)
        if node.left:
            next_layer.append(node.left)
        if node.right:
            next_layer.append(node.right)
        layer = next_layer
        result.append(cur_layer_val)
