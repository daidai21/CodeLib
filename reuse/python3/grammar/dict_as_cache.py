#!/usr/bin/env python3


# Ref: https://gist.github.com/rochacbruno/565377f755f35cebe523a0ac1f7ac8cd


class DictCache(dict):
    def __init__(self, func):
        self.func = func

    def __call__(self, *args):
        print("called for {}".format(args))
        return self[args]

    def __missing__(self, key):
        print("computed for {}".format(key))
        result = self[key] = self.func(*key)
        return result


@DictCache
def sum(a:int, b:int) -> int:
    return a + b


if __name__ == "__main__":
    print(sum(1, 4))  # computed
    print(sum(3, 5))  # computed

    print(sum(1, 4))  # cached
    print(sum(3, 5))  # cached
