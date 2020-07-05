// std::atomic_flag

// compile command
// g++ atomic_flag_example.cpp -pthread -std=c++11 -D USING_ATOMIC; ./a.out | uniq | wc -l
// g++ atomic_flag_example.cpp -pthread -std=c++11; ./a.out | uniq | wc -l


#include <thread>
#include <vector>
#include <iostream>
#include <atomic>
#include <chrono>


#if USING_ATOMIC
std::atomic_flag lock = ATOMIC_FLAG_INIT;
#endif // USING_ATOMIC


// like spin lock
void func(int n) {
#if USING_ATOMIC
  while (lock.test_and_set(std::memory_order_acquire)); // acquire lock
#endif // USING_ATOMIC
  for (int i = 0; i < 100; ++i) {
    std::cout << "Output from thread #" << n << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(1));
  }
#if USING_ATOMIC
  lock.clear(std::memory_order_release); // release lock
#endif // USING_ATOMIC
}

int main() {
  std::vector<std::thread> threads;
  for (int i = 0; i < 10; ++i) {
    threads.emplace_back(func, i);
  }

  for (std::thread& t : threads) {
    t.join();
  }

  return 0;
}
