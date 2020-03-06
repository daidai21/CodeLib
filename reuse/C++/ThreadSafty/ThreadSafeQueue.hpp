/* =============================================================================
> File Name: ThreadSafeQueue.hpp
> Author: DaiDai
> Mail: daidai4269@aliyun.com
> Created Time: Fri 29 Nov 2019 06:14:30 PM CST
============================================================================= */


#ifndef THREADSAFEQUEUE_HPP_
#define THREADSAFEQUEUE_HPP_


#include <queue>
#include <mutex>


template <typename T>
class ThreadSafeQueue {
 public:
  ThreadSafeQueue() {}
  ~ThreadSafeQueue() {}

  const T& front() {
    std::unique_lock<std::mutex> lock(mutex_);
    return queue_.front();
  }

  const T& back() {
    std::unique_lock<std::mutex> lock(mutex_);
    return queue_.back();
  }

  bool empty() {
    std::unique_lock<std::mutex> lock(mutex_);
    return queue_.empty();
  }

  int size() {
    std::unique_lock<std::mutex> lock(mutex_);
    return queue_.size();
  }

  void push(T t) {
    std::unique_lock<std::mutex> lock(mutex_);
    queue_.push(t);
  }

  // TODO: emplace

  void pop() {
    T t;
    this->pop(t);
  }

  bool pop(T& t) {
    std::unique_lock<std::mutex> lock(mutex_);
    if (queue_.empty())
      return false;
    t = queue_.back();
    queue_.pop();
    return true;
  }

  // void swap(T& t); // TODO

 private:
  std::queue<T> queue_;
  std::mutex mutex_;
};


#endif // THREADSAFEQUEUE_HPP_

