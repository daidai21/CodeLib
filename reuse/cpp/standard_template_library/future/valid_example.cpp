#include <iostream>
#include <future>
#include <chrono>
#include <thread>


std::future<int> launcher(std::packaged_task<int(int)>& tsk, int arg) {
  if (tsk.valid()) {
    std::future<int> res = tsk.get_future();
    std::thread (std::move(tsk), arg).detach();
    return res;
  } else {
    std::future<int> ();
  }
}

int main() {
  std::packaged_task<int(int)> tsk ( [](int x) { return x * 2; } );

  std::future<int> fut = launcher(tsk, 25);

  std::cout << "The double of 25 is " << fut.get() << std::endl;

  return 0;
}

