#include <iostream>
#include <atomic>
#include <thread>


std::atomic<bool> ready(false);
std::atomic_flag winner = ATOMIC_FLAG_INIT;


void do_cnt_1m(int id) {
  while (!ready) {
    std::this_thread::yield();
  }

  for (volatile int i = 0; i < 1000000; ++i); // count

  if (!winner.test_and_set()) {
    std::cout << "thread #" << id << std::endl;
  }

}

int main() {
  std::thread threads[10];
  std::cout << "spawning 10 threads that count to 1 million..." << std::endl;
  for (int i = 0; i < 10; ++i) {
    threads[i] = std::thread(do_cnt_1m, i + 1);
  }
  ready = true;

  for (std::thread& t : threads) {
    t.join();
  }

  return 0;
}

