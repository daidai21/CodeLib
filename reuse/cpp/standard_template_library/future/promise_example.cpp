#include <iostream>
#include <functional>
#include <thread>
#include <future>


void print_int(std::future<int>& fut) {
  int x = fut.get();
  std::cout << "value: " << x << std::endl;
}


int main() {
  std::promise<int> prom;
  std::future<int> fut = prom.get_future();
  std::thread t(print_int, std::ref(fut));
  prom.set_value(10);
  t.join();

  return 0;
}

