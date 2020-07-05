#include <iostream>
#include <future>
#include <chrono>
#include <thread>


int main() {
  std::packaged_task<int(int)> foo;

  std::packaged_task<int(int)> bar( [](int x) {return x * 2; } );

  foo = std::move(bar);

  std::future<int> res = foo.get_future();
  std::thread(std::move(foo), 10).detach();

  int val = res.get();
  std::cout << "The double of 10 is " << val << std::endl;

  return 0;
}

