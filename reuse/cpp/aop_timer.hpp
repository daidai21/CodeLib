/* ****************************************************************************
 * File Name   : aop_timer.hpp
 * Author      : DaiDai
 * Mail        : daidai4269@aliyun.com
 * Created Time: 五  9/11 01:51:07 2020
 *************************************************************************** */


// TODO
// not test


#ifndef __AOP_TIMER_HPP__
#define __AOP_TIMER_HPP__


#include <iostream>
#include <chrono>


class AopTimer {
 public:
  void before() {
    this->begin = std::chrono::high_resolution_clock::now();
  }

  void after() {
    long long int run_time = 
        std::chrono::duration_cast<std::chrono::milliseconds>(
          std::chrono::high_resolution_clock::now() - this->begin
    ).count();
    std::cout << "AopTimer used time: " << run_time << " s" << std::endl;
  }

 private:
  std::chrono::time_point<std::chrono::high_resolution_clock> begin;
};


#endif // __AOP_TIMER_HPP__
