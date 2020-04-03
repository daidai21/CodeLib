#include <iostream>
#include <future>
#include <chrono>
#include <thread>


void do_print_ten(char c, int ms) {
  for (int i = 0; i < 10; ++i) {
    std::this_thread::sleep_for(std::chrono::milliseconds(ms));
    std::cout << c;
  }
}

int main() {
  std::cout << "with std::launch::async" << std::endl;
  std::future<void> foo = std::async(std::launch::async, do_print_ten, '*', 100);
  std::future<void> bar = std::async(std::launch::async, do_print_ten, '@', 200);
  foo.get();
  bar.get();
  std::cout << "\n" << std::endl;

  std::cout << "with std::launch::deferred" << std::endl;
  foo = std::async(std::launch::deferred, do_print_ten, '*', 100);
  bar = std::async(std::launch::deferred, do_print_ten, '@', 200);
  foo.get();
  bar.get();
  std::cout << "\n" << std::endl;

  return 0;
}

