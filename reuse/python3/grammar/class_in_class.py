
#!/usr/bin/env python

import os
import sys


class parent:
    def __init__(self):
        self.name = 'parent'

    def getName(self):
        print(self.name)

    class child:
        def __init__(self):
            self.name = 'child'

        def getName(self):
            print(self.name)


if __name__ == '__main__':
    child = parent.child()
    child.getName()

    print("*" * 10)

    p = parent()
    p.getName()
    c = p.child()
    c.getName()
