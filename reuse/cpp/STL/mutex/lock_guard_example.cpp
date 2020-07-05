// std::lock_guard


#include <iostream>
#include <thread>
#include <mutex>
#include <stdexcept>


std::mutex mtx;


void print_even(int x) {
  if (x % 2 == 0) {
    std::cout << x << " is even." << std::endl;
  } else {
    throw (std::logic_error("not even"));
  }
}

void print_thread_id(int id) {
  try {
    std::lock_guard<std::mutex> lck(mtx);
    print_even(id);
    // auto unlock
  } catch (std::logic_error&) {
    std::cout << "[exception caught]" << std::endl;
  }
}

int main(int argc, char* argv[]) {
  std::thread threads[10];
  for (int i = 0; i < 10; ++i) {
    threads[i] = std::thread(print_thread_id, i + 1);
  }

  for (std::thread& t : threads) {
    t.join();
  }

  return 0;
}

