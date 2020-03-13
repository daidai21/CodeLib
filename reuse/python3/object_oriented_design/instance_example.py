class Example(object):
    # It's a static method
    # For create object and return object
    def __new__(cls, *args, **kwargs):
        print("Example.__new__()")

        self = super().__new__(cls)
        return self

    # Structure function
    # For object instance
    def __init__(self, *args, **kwargs):
        self.param = args[0]

        print("Example.__init__()", self.param)

    # Like __init__ function, but can't be used instance operate
    # For change private parameters in instance object
    def __call__(self, *args, **kwargs):
        self.param = args[0]

        print("Example.__call__()", self.param)


if __name__ == "__main__":
    c = Example(1)
    c(2)
