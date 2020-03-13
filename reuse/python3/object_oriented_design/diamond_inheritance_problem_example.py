class A:
    def func(self):
        print("A.func()")


class B(A):
    def func(self):
        print("B.func()")


class C(A):
    def func(self):
        print("C.func()")


class D(B, C):
    pass


d = D()
d.func()


################################################################################


class A:
    def func(self):
        print("A.func()")


class B(A):
    pass


class C(A):
    def func(self):
        print("C.func()")


class D(B, C):
    pass


d = D()
d.func()


################################################################################


class A:
    def func(self):
        print("A.func()")


class B(A):
    def func(self):
        print("B.func()")
        A.func(self)


class C(A):
    def func(self):
        print("C.func()")
        A.func(self)


class D(B, C):
    def func(self):
        print("D.func()")
        B.func(self)
        C.func(self)


d = D()
d.func()
