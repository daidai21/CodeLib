/* =============================================================================
> File Name: MonotonicStack.hpp
> Author: DaiDai
> Mail: daidai4269@aliyun.com
> Created Time: Thu 05 Dec 2019 10:17:50 PM CST
============================================================================= */


#ifndef MONOTONICSTACK_HPP_
#define MONOTONICSTACK_HPP_


#include <iostream>
#include <vector>


class MonotonicStack {
 public:
  MonotonicStack() {}
  ~MonotonicStack() {}

  int top() {
    return stk[stk.size() - 1];
  }

  bool empty() {
    return stk.empty();
  }

  int size() {
    return stk.size();
  }

  void push(int n) {
    while (!stk.empty() && stk[stk.size() - 1] >= n)
      stk.pop_back();
    stk.push_back(n);
  }

  int pop() {
    int result = stk[stk.size() - 1];
    stk.pop_back();
    return result;
  }

  void display() {
    std::cout << "bottom --> top: ";
    for (int i = 0; i < stk.size(); ++i)
      std::cout << stk[i] << " ";
    std::cout << std::endl;
  }

 private:
  std::vector<int> stk;

};


#endif // MONOTONICSTACK_HPP_

