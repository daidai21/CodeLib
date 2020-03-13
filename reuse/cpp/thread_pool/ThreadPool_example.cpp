/* =============================================================================
> File Name: ThreadPool_example.cpp
> Author: DaiDai
> Mail: daidai4269@aliyun.com
> Created Time: Fri 29 Nov 2019 10:08:10 PM CST
============================================================================= */


#include "ThreadPool.hpp"

#include <iostream>
#include <chrono>
#include <vector>
#include <future>


using namespace std;


int main() {
  ThreadPool pool(4);
  std::vector<std::future<int>> results;
  for (int i = 0; i < 8; ++i) {
    results.emplace_back(
      pool.submit([i] {
        cout << "hello " << i << endl;
        this_thread::sleep_for(std::chrono::seconds(1));
        cout << "world " << i << endl;
        return i * i;
      })
    );
  }

  for (auto&& result : results)
    cout << result.get() << " ";
  cout << endl;

  return 0;
}

