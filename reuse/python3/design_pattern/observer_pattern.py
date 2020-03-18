#!/usr/bin/env python3
# -*- coding:utf-8 -*-


###############################################################################
# create subject class
###############################################################################
class Subject:
    def __init__(self):
        self._observers = []
        self._state = None

    def get_state(self) -> int:
        return self._state

    def set_state(self, state:int) -> None:
        self._state = state
        self.notify_all_observers()

    def attach(self, observer) -> None:
        self._observers.append(observer)

    def notify_all_observers(self) -> None:
        for observer in self._observers:
            observer.update()


###############################################################################
# create observer class
###############################################################################
class Observer:
    def __init__(self):
        self._subject = Subject()

    def update(self) -> None:
        raiseNotImplemented("Observer.update() not implemented")


###############################################################################
# create the entity observer class
###############################################################################
class BinaryObserver(Observer):
    def __init__(self, subject) -> None:
        self._subject = subject
        self._subject.attach(self)

    def update(self) -> None:
        print("Binary String: {}".format(self._subject.get_state()))


class OctalObserver(Observer):
    def __init__(self, subject) -> None:
        self._subject = subject
        self._subject.attach(self)

    def update(self) -> None:
        print("Octal String: {}".format(self._subject.get_state()))


class HexaObserver(Observer):
    def __init__(self, subject) -> None:
        self._subject = subject
        self._subject.attach(self)

    def update(self) -> None:
        print("Heo String: {}".format(self._subject.get_state()))


###############################################################################
if __name__ == "__main__":
    subject = Subject()

    BinaryObserver(subject)
    OctalObserver(subject)
    HexaObserver(subject)

    print("First state change: 15")
    subject.set_state(15)
    print("Second state change: 10")
    subject.set_state(10)

