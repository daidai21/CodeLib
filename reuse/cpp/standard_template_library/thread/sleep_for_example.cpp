#include <iostream>
#include <chrono>
#include <thread>


int main() {
  std::cout << "start waiter" << std::endl;
  std::chrono::milliseconds duration(1000);
  std::this_thread::sleep_for(duration);
  std::cout << "waited 1000ms" << std::endl;

  return 0;
}
