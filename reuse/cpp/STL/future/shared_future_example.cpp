#include <iostream>
#include <future>


int do_get_val() {
  return 10;
}

int main() {
  std::future<int> fut = std::async(do_get_val);
  std::shared_future<int> shared_fut = fut.share();

  // std::cout << fut.get() << std::endl;
  std::cout << "value: " << shared_fut.get() << std::endl;
  std::cout << "it's double: " << shared_fut.get() * 2 << std::endl;

  return 0;
}

