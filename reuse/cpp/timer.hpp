/* ****************************************************************************
 * File Name   : timer.hpp
 * Author      : DaiDai
 * Mail        : daidai4269@aliyun.com
 * Created Time: 五  9/11 02:31:37 2020
 *************************************************************************** */

#ifndef __TIMER_HPP__
#define __TIMER_HPP__

#include <chrono>

class Timer {
 public:
  Timer() {
    begin = std::chrono::high_resolution_clock::now();
  }

  void reset() {
    begin = std::chrono::high_resolution_clock::now();
  }

  // default milliseconds
  template <typename DurationType = std::chrono::milliseconds>
  long long int elapsed() const {
    return std::chrono::duration_cast<DurationType>(std::chrono::high_resolution_clock::now() - begin).count();
  }

  long long int elapsed_milliseconds() const {
    return elapsed<std::chrono::milliseconds>();
  }

  long long int elapsed_microseconds() const {
    return elapsed<std::chrono::microseconds>();
  }

  long long int elapsed_nanoseconds() const {
    return elapsed<std::chrono::nanoseconds>();
  }

  long long int elapsed_seconds() const {
    return elapsed<std::chrono::seconds>();
  }

  long long int elapsed_minutes() const {
    return elapsed<std::chrono::minutes>();
  }

  long long int elapsed_hour() const {
    return elapsed<std::chrono::hours>();
  }

 private:
  std::chrono::time_point<std::chrono::high_resolution_clock> begin;
};

#endif  // __TIMER_HPP__
