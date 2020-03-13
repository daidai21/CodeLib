# MRO example
class A:
    def func(self):
        print("A.func()")


class B(A):
    def func(self):
        print("B.func()")
        super().func()


class C(A):
    def func(self):
        print("C.func()")
        super().func()


class D(B, C):
    def func(self):
        print("D.func()")
        super().func()


d = D()
d.func()
