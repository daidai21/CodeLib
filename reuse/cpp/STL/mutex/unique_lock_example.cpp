// std::unique_lock


#include <iostream>
#include <thread>
#include <mutex>
#include <stdexcept>


std::mutex mtx;


void print_block(int n, char c) {
  std::unique_lock<std::mutex> lck(mtx);
  for (int i = 0; i < n; ++i) {
    std::cout << c;
  }
  std::cout << std::endl;
}

int main(int argc, char* argv[]) {
  std::thread t1(print_block, 50, '*');
  std::thread t2(print_block, 50, '%');

  t1.join();
  t2.join();

  return 0;
}
