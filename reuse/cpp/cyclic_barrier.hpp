/* ****************************************************************************
 * File Name   : cyclic_barrier.hpp
 * Author      : DaiDai
 * Mail        : daidai4269@aliyun.com
 * Created Time: 五  9/11 02:36:00 2020
 *************************************************************************** */

#ifndef __CYCLIC_BARRIER_HPP__
#define __CYCLIC_BARRIER_HPP__

#include <condition_variable>
#include <mutex>

// TODO: https://github.com/nipuntalukdar/cyclicbarrier/blob/master/cyclicbarrier.hpp
// 看下jdk源码


/*
https://github.com/nipuntalukdar/cyclicbarrier
https://github.com/anandkulkarnisg/CyclicBarrier
https://blog.csdn.net/xin_hen/article/details/107821970
https://stackoverflow.com/questions/48241351/what-is-c-version-of-javas-cyclic-barrier
*/

#define CallBack int // TODO

class CyclicBarrier {
 public:
  CyclicBarrier(unsigned int parties) : parties_(parties) {
    current_waits = 0;
  }

  CyclicBarrier(unsigned int parties, CallBack* callback) : parties_(parties) {
    current_waits = 0;
  }

  void await() {
    // TODO
  }

  void await(long int timeout) {
    // TODO
  } // time unit

  unsigned int get_num_waiting() {
    std::lock_guard<std::mutex> lck(const_cast<std::mutex&>(mtx_));
    return current_waits;
  }

  unsigned int get_parites() const {
    std::lock_guard<std::mutex> lck(const_cast<std::mutex&>(mtx_));
    return parties_;
  }

  bool is_broken() {
    // TODO: class Generation
  }

  void reset() {
    // TODO
  }

 private:
  std::mutex mtx_;
  std::condition_variable cond_;
  unsigned int parties_;
  unsigned int current_waits;

 private:
  CyclicBarrier() = delete;
  CyclicBarrier(const CyclicBarrier& other) = delete;
  CyclicBarrier& operator=(const CyclicBarrier& opther) = delete;

 private:
  void next_generation();
  void break_barrier();
  int dowait(bool timed, long nanos);
};

#endif  // __CYCLIC_BARRIER_HPP__
