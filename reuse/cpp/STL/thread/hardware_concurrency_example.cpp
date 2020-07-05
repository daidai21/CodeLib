// Number of physical threads

#include <iostream>
#include <thread>


int main() {
  unsigned int n = std::thread::hardware_concurrency();
  std::cout << n << " concurrent threads are supported." << std::endl;

  return 0;
}
