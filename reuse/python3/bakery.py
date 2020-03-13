#!/usr/bin/python3 env


"""
An implementation of Lamport's Bakery Algorithm.
Wiki link: https://en.wikipedia.org/wiki/Lamport%27s_bakery_algorithm
reference link: https://github.com/keyan/lamport-bakery-algorithm
"""


import threading
import time


class Lock(object):
    def __init__(self, num_threads: int) -> None:
        self.num_threads = num_threads

        self.entering = [False for _ in range(num_threads)]
        self.number   = [0     for _ in range(num_threads)]

    def acquire(self, thread_id: int) -> None:
        self.entering[thread_id] = True
        self.number[thread_id] = max(self.number) + 1
        self.entering[thread_id] = False

        for j in range(self.num_threads):
            while self.entering[j] != 0:
                pass
            while self.number[j] != 0 and (self.number[j], j) < (self.number[thread_id], thread_id):
                pass

    def release(self, thread_id: int) -> None:
        self.number[thread_id] = False


def safe_modify_state():
    global lock
    global safe_counter

    thread_id = int(threading.current_thread().name) - 1
    try:
        lock.acquire(thread_id)
        tmp = safe_counter
        time.sleep(0.01)
        safe_counter = tmp + 1
        print(safe_counter)
    finally:
        lock.release(thread_id)


def unsafe_modify_state():
    global unsafe_counter

    tmp = unsafe_counter
    time.sleep(0.01)
    unsafe_counter = tmp + 1
    print(unsafe_counter)


if __name__ == "__main__":
    NUM_THREADS = 20
    lock = Lock(NUM_THREADS)

    # Trying to increment to 100 and print without locking results in undeterministic weird output.
    print("unsafe_counter")
    unsafe_counter = 0
    thread_pool = [threading.Thread(target=unsafe_modify_state, name=i) for i in range(1, NUM_THREADS + 1)]
    for thread in thread_pool:
        thread.start()

    for thread in thread_pool:
        thread.join()

    # Trying to increment to 100 and print with locking results in undeterministic weird output.
    print("safe_counter")
    safe_counter = 0
    thread_pool = [threading.Thread(target=safe_modify_state, name=i) for i in range(1, NUM_THREADS + 1)]
    for thread in thread_pool:
        thread.start()
