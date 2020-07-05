// std::recursive_mutex
// BUG: https://github.com/forhappy/Cplusplus-Concurrency-In-Practice/blob/master/zh/chapter4-Mutex/4.2%20Mutex-tutorial.md#stdrecursive_mutex-%E4%BB%8B%E7%BB%8D


#include <iostream>
#include <thread>
#include <mutex>


class Counter {
 public:
  Counter() : cnt(0) {}

  int add(int val) {
    std::recursive_mutex::scoped_lock scoped_lock(this->mtx);
    this->cnt += val;
    return this->cnt;
  }

  int increment() {
    std::recursive_mutex::scoped_lock scoped_lock(this->mtx);
    return this->add(1);
  }

 private:
  std::recursive_mutex mtx;
  int cnt;
};

Counter c;

void change_cnt() {
  std::cout << "count == " << c.increment() << std::endl;
}

int main(int argc, char* argv[]) {
  std::thread threads[10];
  for (int i = 0; i < 10; ++i) {
    threads[i] = std::thread(change_cnt);
  }

  for (std::thread& t : threads) {
    t.join();
  }

  return 0;
}

