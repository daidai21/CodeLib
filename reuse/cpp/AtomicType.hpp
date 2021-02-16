/* ****************************************************************************
 * File Name   : AtomicType.hpp
 * Author      : DaiDai
 * Mail        : daidai4269@aliyun.com
 * Created Time: 二  2/16 16:25:00 2021
 *************************************************************************** */

/**
 * atomic operator template class, like Java API
 * 
 * C++11
 */

#ifndef __ATOMIC_HPP__
#define __ATOMIC_HPP__

#include <atomic>

template <typename T>
class AtomicType {
 public:
  AtomicType() : value_(0) {}
  AtomicType(T value) : value_(value) {}

  T get() { return this->value_; }
  void set(T value) { this->value_ = value; }

  // The assignment operator
  void operator=(int value) { this->value_ = value; }

  // The increment and decrement operators
  // Overloading the prefix increment operator; ++i
  T operator++() { this->value_++; return this->get(); }
  T operator--() { this->value_--; return this->get(); }
  // Overloading the postfix increment operator; i++
  T operator++(T) { T result = this->get(); this->value_++; return result; }
  T operator--(T) { T result = this->get(); this->value_--; return result; }

  // Relational operator
  bool operator==(T value) { return this->get() == value; }
  bool operator!=(T value) { return this->get() != value; }
  bool operator>(T value) { return this->get() > value; }
  bool operator<(T value) { return this->get() < value; }
  bool operator>=(T value) { return this->get() >= value; }
  bool operator<=(T value) { return this->get() <= value; }

  // Change value
  void inc() { this->value_++; }
  void dec() { this->value_--; }
  void add(int value) { this->value_.fetch_add(value, std::memory_order_relaxed); }
  void sub(int value) { this->value_.fetch_sub(value, std::memory_order_relaxed); }

  // Increment and get
  int inc_and_get() { this->inc(); return this->get(); }
  // Decrease and get
  int dec_and_get() { this->dec(); return this->get(); }

  int add_and_get(int value) { this->add(value); return this->get(); }
  int sub_and_get(int value) { this->sub(value); return this->get(); }

  int get_and_inc() { T result = this->get(); this->inc(); return result; }
  int get_and_dec() { T result = this->get(); this->dec(); return result; }

  int get_and_add(T value) { T result = this->get(); this->add(value); return result; }
  int get_and_sub(T value) { T result = this->get(); this->sub(value); return result; }

 private:
  std::atomic<T> value_;
};

#endif  // __ATOMIC_HPP__
