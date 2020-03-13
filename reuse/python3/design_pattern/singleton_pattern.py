class SingletonExample(object):
    __singleton = None

    def __new__(cls, *args, **kwargs):
        if not cls.__singleton:
            cls.__singleton = object.__new__(cls, *args, **kwargs)
        return cls.__singleton


c1 = SingletonExample()
c2 = SingletonExample()
print(c1 is c2)
print(c1 == c2)
print(id(c1) == id(c2))

