/* ****************************************************************************
 * File Name   : count_down_latch.hpp
 * Author      : DaiDai
 * Mail        : daidai4269@aliyun.com
 * Created Time: 五  9/11 02:34:58 2020
 *************************************************************************** */

#ifndef __COUNT_DOWN_LATCH_HPP__
#define __COUNT_DOWN_LATCH_HPP__

#include <condition_variable>
#include <iostream>
#include <mutex>

class CountDownLatch {
 public:
  CountDownLatch(int cnt) : cnt_(cnt) {}

  void count_down() {
    std::unique_lock<std::mutex> lock(mtx_);
    --cnt_;
    if (cnt_ <= 0) {
      cond_.notify_one();
    }
  }

  void await() {
    std::unique_lock<std::mutex> lock(mtx_);
    while (cnt_ > 0) {
      cond_.wait(lock);
    }
  }

 private:
  std::mutex mtx_;
  std::condition_variable cond_;
  int cnt_;
};

#endif  // __COUNT_DOWN_LATCH_HPP__
