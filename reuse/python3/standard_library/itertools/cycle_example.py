#!/usr/bin/env python3


import itertools


i = 0
for item in itertools.cycle(['a', 'b', 'c']):
    i += 1
    if i == 10:
        break
    print(i, item)

