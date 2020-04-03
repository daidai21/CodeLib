#include <iostream>
#include <atomic>
#include <thread>


std::atomic<int> foo(0);


void set_foo(int x) {
  foo.store(x, std::memory_order_relaxed);
}


void print_foo() {
  // std::cout << foo.load(std::memory_order_relaxed) << std::endl;
  int x;
  do {
    x = foo.load(std::memory_order_relaxed);
  } while(x == 0);
  std::cout << "foo: " << x << std::endl;
}

int main() {
  std::thread first(print_foo);
  std::thread second(set_foo, 10);
  first.join();
  second.join();

  return 0;
}

