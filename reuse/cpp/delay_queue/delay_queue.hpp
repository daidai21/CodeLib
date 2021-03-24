/* ****************************************************************************
 * File Name   : delay_queue.hpp
 * Author      : DaiDai
 * Mail        : daidai4269@aliyun.com
 * Created Time: 一  3/ 1 16:27:08 2021
 *************************************************************************** */

#include <vector>
// TODO: like java.util.concurrent.DelayQueue
// https://github.com/openjdk-mirror/jdk7u-jdk/blob/master/src/share/classes/java/util/concurrent/DelayQueue.java
class Delayed {
 public:
  virtual long int get_delay();
};

template <typename T>
class DelayQueue {
 public:
  DelayQueue();

  ~DelayQueue();

  bool add(T t);

  T poll();

  E take();

  T peek();

  int size();

  int drain_to();

  void clear();

  int remaining_capacity();

  std::vector<T> to_vector();

  bool remove(T t);

 private:
  // ReentrantLock
  // PriorityQueue
};
