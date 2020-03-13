class CanInstanceClass:
    def func(self, param: int):
        print(type(param), param)
        print("CanInstanceClass.func()")


class NoInstances(type):
    def __call__(self, *args, **kwargs):
        raise TypeError("Can't instantiate directly")


class CanNotInstanceClass(metaclass=NoInstances):
    @staticmethod
    def func(param: int):
        print(type(param), param)
        print("CanNotInstanceClass.func()")


# CanInstanceClass.func(12)  # Error
c = CanInstanceClass()
c.func(12)

CanNotInstanceClass.func(42)
# c = CanNotInstanceClass()  # Error


################################################################################
# Singleton
################################################################################


class Singleton(type):
    def __init__(self, *args, **kwargs):
        self.__instance = None
        super().__init__(*args, **kwargs)

    def __call__(self, *args, **kwargs):
        if self.__instance is None:
            self.__instance = super().__call__(*args, **kwargs)
        return self.__instance


class SingletonExample(metaclass=Singleton):
    def __init__(self):
        print("Creating SingletonExample")


instance_class1 = SingletonExample()
instance_class2 = SingletonExample()
print(instance_class1 is instance_class2)
print(instance_class1 == instance_class2)
print(id(instance_class1) == id(instance_class2))


################################################################################
# Cached example
################################################################################


# a weak references module
import weakref


class Cached(type):
    def __init__(self, *args, **kwargs):
        super().__init__(*args, **kwargs)
        self.__cache = weakref.WeakValueDictionary()

    def __call__(self, *args):
        if args in self.__cache:
            return self.__cache[args]
        else:
            obj = super().__call__(*args)
            self.__cache[args] = obj
            return obj
