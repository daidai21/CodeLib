/* =============================================================================
> File Name: MaxMinStack.hpp
> Author: DaiDai
> Mail: daidai4269@aliyun.com
> Created Time: Wed 11 Dec 2019 12:59:38 PM CST
============================================================================= */


#include <stack>


template<typename Type>
class MaxStack {
 public:
  MaxStack() {}
  ~MaxStack() {}

  Type top() {
    return stack_.top();
  }

  bool empty() {
    return stack_.empty();
  }

  int size() {
    return stack_.size();
  }

  void push(const Type& val) {
    if (stack_.size() == 0) {
      stack_.push(val);
      stack_max_.push(val);
    } else {
      stack_.push(val);
      if (val > stack_max_.top())
        stack_max_.push(val);
      else
        stack_max_.push(stack_max_.top());
    }
  }

  void pop() {
    stack_.pop();
    stack_max_.pop();
  }

  // TODO: void swap(Type& stk) {}

  Type get_max() {
    return stack_max_.top();
  }

 private:
  std::stack<Type> stack_;
  std::stack<Type> stack_max_;
};


template<typename Type>
class MinStack{
 public:
  MinStack() {}
  ~MinStack() {}

  Type top() {
    return stack_.top();
  }

  bool empty() {
    return stack_.empty();
  }

  int size() {
    return stack_.size();
  }

  void push(const Type& val) {
    if (stack_.size() == 0) {
      stack_.push(val);
      stack_min_.push(val);
    } else {
      stack_.push(val);
      if (val < stack_min_.top())
        stack_min_.push(val);
      else
        stack_min_.push(stack_min_.top());
    }
  }

  void pop() {
    stack_.pop();
    stack_min_.pop();
  }

  // TODO: void swap(Type& stk) {}

  Type get_max() {
    return stack_min_.top();
  }

 private:
  std::stack<Type> stack_;
  std::stack<Type> stack_min_;
};

