/* ****************************************************************************
 * File Name   : timer_example.cpp
 * Author      : DaiDai
 * Mail        : daidai4269@aliyun.com
 * Created Time: 二 11/10 11:39:42 2020
 *************************************************************************** */

#include "./timer.hpp"

#include <iostream>
#include <thread>

using namespace std;

int main(int argc, char* argv[]) {
  Timer timer;
  std::this_thread::sleep_for(std::chrono::seconds(1));

  std::cout << timer.elapsed() << std::endl;
  std::cout << timer.elapsed_milliseconds() << std::endl;
  std::cout << timer.elapsed_microseconds() << std::endl;
  std::cout << timer.elapsed_nanoseconds() << std::endl;
  std::cout << timer.elapsed_seconds() << std::endl;
  std::cout << timer.elapsed_minutes() << std::endl;
  std::cout << timer.elapsed_hour() << std::endl;

  return 0;
}
