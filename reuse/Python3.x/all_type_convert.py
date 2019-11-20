#!/usr/bin/env python3
# -*- coding:utf-8 -*-


# =============================================================================
# File Name: all_type_convert.py
# Author: DaiDai
# Mail: daidai4269@aliyun.com
# Created Time: Tue 19 Nov 2019 08:44:33 PM CST
# =============================================================================


get_type_str = lambda var: str(type(var)).replace("'", "").replace("class", "").replace(" ", "").replace("<", "").replace(">", "")


# start int type
start = 1
# int -> str
end = str(start)
print(get_type_str(start), "->", get_type_str(end), start, end)
# int -> float
end = float(start)
print(get_type_str(start), "->", get_type_str(end), start, end)


# start float type
start = 1.1
# flaot -> str
end = str(start)
print(get_type_str(start), "->", get_type_str(end), start, end)
# float -> int
end = int(start)
print(get_type_str(start), "->", get_type_str(end), start, end)


# start str type
start = "1"
# str -> int
end = int(start)
print(get_type_str(start), "->", get_type_str(end), start, end)
# str -> float
start = "1.1"
end = float(start)
print(get_type_str(start), "->", get_type_str(end), start, end)
# str -> list
import ast
start = '["1", "2", "3"]'
end = ast.literal_eval(start)
print(get_type_str(start), "->", get_type_str(end), start, end)
# str -> dict
start = '{"1": "a", "2": "b"}'
import ast
end = ast.literal_eval(start)
print(get_type_str(start), "->", get_type_str(end), start, end)
import json
end = json.loads(start)
print(get_type_str(start), "->", get_type_str(end), start, end)
# str -> tuple
start = '(1, 2, 3)'
import ast
end = ast.literal_eval(start)
print(get_type_str(start), "->", get_type_str(end), start, end)
# str -> set
start = '11233'
end = set(start)
print(get_type_str(start), "->", get_type_str(end), start, end)


# start list type
start = [1, 2, 3]
# list -> str
end = str(start)
print(get_type_str(start), "->", get_type_str(end), start, end)
# list -> tuple
end = tuple(start)
print(get_type_str(start), "->", get_type_str(end), start, end)
# list -> set
end = set(start)
print(get_type_str(start), "->", get_type_str(end), start, end)


# start tuple type
start = (1, 2 ,3)
# tuple -> list
end = list(start)
print(get_type_str(start), "->", get_type_str(end), start, end)
# tuple -> set
end = set(start)
print(get_type_str(start), "->", get_type_str(end), start, end)
# tuple -> str
end = str(start)
print(get_type_str(start), "->", get_type_str(end), start, end)


# start set type
start = {1, 2 ,3}
# set -> list
end = list(start)
print(get_type_str(start), "->", get_type_str(end), start, end)
# set -> tuple
end = tuple(start)
print(get_type_str(start), "->", get_type_str(end), start, end)
# set -> str
end = str(start)
print(get_type_str(start), "->", get_type_str(end), start, end)


# start dict type
start = {
    'a': 1,
    'b': 2
}
# dict -> list
end = list(start)
print(get_type_str(start), "->", get_type_str(end), start, end)
# dict -> list
end = [(k, start[k]) for k in start]
print(get_type_str(start), "->", get_type_str(end), start, end)
# dict -> list
end = [k for k in start] + [start[k] for k in start]
print(get_type_str(start), "->", get_type_str(end), start, end)
# dict -> tuple
end = tuple(start)
print(get_type_str(start), "->", get_type_str(end), start, end)
# dict -> tuple
end = tuple(start[k] for k in start)
print(get_type_str(start), "->", get_type_str(end), start, end)
# dict -> tuple
end = tuple(k for k in start) + tuple(start[k] for k in start)
print(get_type_str(start), "->", get_type_str(end), start, end)
# dict -> set
end = set(start)
print(get_type_str(start), "->", get_type_str(end), start, end)
# dict -> set
end = set(start[k] for k in start)
print(get_type_str(start), "->", get_type_str(end), start, end)
# dict -> set
end = set.union(set(start[k] for k in start), set(start))
print(get_type_str(start), "->", get_type_str(end), start, end)
# dict -> str
end = str(start)
print(get_type_str(start), "->", get_type_str(end), start, end)
