#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
#include <condition_variable>


std::condition_variable cv;
char                    input;


void do_read_input() {
  std::cin >> input;
  cv.notify_one();
}

int main() {
  std::cout << "Please, enter an char." << std::endl;
  std::thread t(do_read_input);

  std::mutex mtx;
  std::unique_lock<std::mutex> lck(mtx);
  while (cv.wait_for(lck, std::chrono::seconds(1)) == std::cv_status::timeout) {
    std::cout << ".";
    std::cout.flush();
  }
  std::cout << "You entered: " << input << std::endl;
  t.join();

  return 0;
}

