#include <iostream>
#include <future>
#include <chrono>
#include <thread>


int main() {
  std::packaged_task<int(int)> tsk ( [](int x) { return x * 3; } );

  std::future<int> fut = tsk.get_future();

  std::thread (std::move(tsk), 100).detach();

  std::cout << "The double of 100 is " << fut.get() << std::endl;

  return 0;
}

