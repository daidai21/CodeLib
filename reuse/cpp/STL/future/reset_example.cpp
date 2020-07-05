#include <iostream>
#include <future>
#include <thread>
#include <utility>


int triple(int x) {
  return x * 3;
}

int main() {
  std::packaged_task<int(int)> tsk(triple);

  std::future<int> fut = tsk.get_future();
  // std::thread (std::move(tsk), 100).detach();
  tsk(100);
  std::cout << "The triple of 100 is " << fut.get() << std::endl;

  tsk.reset();
  fut = tsk.get_future();
  std::thread (std::move(tsk), 200).detach();
  std::cout << "The triple of 200 is " << fut.get() << std::endl;

  return 0;
}

