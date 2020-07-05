#include <iostream>
#include <functional>
#include <thread>
#include <future>
#include <exception>


void get_int(std::promise<int>& prom) {
  int x;
  std::cout << "please, enter an integer value: ";
  std::cin.exceptions (std::ios::failbit);
  try {
    std::cin >> x;
    prom.set_value(x);
  } catch(std::exception&) {
    prom.set_exception(std::current_exception());
  }
}

void print_int(std::future<int>& fut) {
  try {
    int x = fut.get();
    std::cout << "value: " << x << std::endl;
  } catch(std::exception& e) {
    std::cout << "[excaption caught: " << e.what() << "]" << std::endl;
  }
}

int main() {
  std::promise<int> prom;
  std::future<int> fut = prom.get_future();

  std::thread t1(get_int, std::ref(prom));
  std::thread t2(print_int, std::ref(fut));

  t1.join();
  t2.join();

  return 0;
}

