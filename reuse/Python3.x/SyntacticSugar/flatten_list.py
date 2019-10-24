#!/usr/bin/env python3
# -*- coding:utf-8 -*-


# =============================================================================
# File Name: flatten_list.py
# Author: DaiDai
# Mail: daidai4269@aliyun.com
# Created Time: Thu Oct 24 13:57:03 2019
# =============================================================================


def flatten(lst):
    """
    example:
        float -> [float]
        int -> [int]
        [] -> []
        [, , , ] -> [, , , ]
        [[], [, , ]] -> [, , , , , ]

    max dimension is 600
    """
    def expand_list(lst):
        for item in lst:
            if isinstance(item, (list, tuple)):
                for sub_item in expand_list(item):
                    yield sub_item
            else:
                yield item

    return [lst] if isinstance(lst, (int, float)) else list(expand_list(lst))
