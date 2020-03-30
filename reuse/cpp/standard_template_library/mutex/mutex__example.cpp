// std::mutex.try_lock()


#include <iostream>
#include <thread>
#include <mutex>


volatile int counter = 0;
std::mutex mtx;


void attempt_10k_increases() {
  for (int i = 0; i < 10000; ++i) {
    if (mtx.try_lock()) {
      ++counter;
      mtx.unlock();
    }
  }
}

int main(int argc, char* argv[]) {
  std::thread threads[10];
  for (int i = 0; i < 10; ++i) {
    threads[i] = std::thread(attempt_10k_increases);
  }

  for (std::thread& t : threads) {
    t.join();
  }

  std::cout << counter << " successful increases of the counter." << std::endl;

  return 0;
}

