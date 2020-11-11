/* ****************************************************************************
 * File Name   : count_down_latch_example.cpp
 * Author      : DaiDai
 * Mail        : daidai4269@aliyun.com
 * Created Time: 一 11/ 9 16:51:59 2020
 *************************************************************************** */

#include <iostream>
#include <thread>

#include "./count_down_latch.hpp"

using namespace std;

CountDownLatch CDL(3);

void worker(const std::string& name) {
  std::cout << name << " working ..." << std::endl;
  std::this_thread::sleep_for(std::chrono::seconds(1));
  CDL.count_down();
  std::cout << name << " finished" << std::endl;
}

void boss() {
  std::cout << "boss wait ..." << std::endl;
  CDL.await();
  std::cout << "boss start check ..." << std::endl;
}

int main(int argc, char* argv[]) {
  std::thread b(boss);
  std::thread w1([]{ worker("tom"); });
  std::thread w2([]{ worker("jerry"); });
  std::thread w3([]{ worker("marry"); });

  b.join();
  w1.join();
  w2.join();
  w3.join();

  return 0;
}
