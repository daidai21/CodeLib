/* =============================================================================
> File Name: ThreadSafeQueue_test.cpp
> Author: DaiDai
> Mail: daidai4269@aliyun.com
> Created Time: Fri 29 Nov 2019 07:18:38 PM CST
============================================================================= */


#include "ThreadSafeQueue.hpp"

#include <stdlib.h>
#include <stdio.h>

#include <iostream>
#include <queue>
#include <thread>


using namespace std;


void test_logic_error() {
  cout << "test_logic_error()" << endl;
  ThreadSafeQueue<int> thread_safe_queue_;
  queue<int> queue_;

  for (int i = 0; i < 1000; ++i) {
    int rand_val = rand();
    if (rand_val & 1 == 1) {
      // push
      thread_safe_queue_.push(rand_val);
      queue_.push(rand_val);
      cout << "Push " << rand_val << endl;
    } else {
      if (thread_safe_queue_.back() != queue_.back()) {
        cout << "Error: " << thread_safe_queue_.back() << " " << queue_.back() << endl;
        return ;
      }
      int temp = thread_safe_queue_.back();
      // pop
      thread_safe_queue_.pop();
      queue_.pop();
      cout << "Pop " << temp << endl;
    }
  }
}


void queue_thread_safety_counter_example() {
  long long int var = 0;
  auto func = [&]() {
    for (int i = 0; i < 100; ++i) {
      var++;
      cout << var << endl;
    }
  };
  thread t1(func);
  thread t2(func);
  t1.join();
  t2.join();
}


void test_thread_safety() { // BUG: incomplete coverage of test samples
  // Push
  cout << "test_thread_safety()" << endl;
  queue<int> queue_;
  queue_.push(1);
  auto func = [&](int thread_id) {
    for (int i = 0; i < 1000; ++i) {
      int temp = queue_.back() + 1;
      queue_.push(temp);
      // this_thread::sleep_for(0.1s);
      // cout << unitbuf << "thread " << thread_id << ": " << temp << "\n" << flush;
      printf("thread %d: %d\n", thread_id, temp);
      // this_thread::sleep_for(0.1s);
    }
  };
  thread t1(func, 1);
  thread t2(func, 2);
  thread t3(func, 3);
  t1.join();
  t2.join();
  t3.join();

  // Check
  // BUG: check logic error
  int val = queue_.front();
  queue_.pop();
  while (!queue_.empty()) {
    if (val + 1 != queue_.front()) {
      cout << "Error: " << val << " " << queue_.front() << endl;
      return ;
    }
    val++;
    queue_.pop();
  }
}


int main() {
  test_logic_error();
  queue_thread_safety_counter_example();
  test_thread_safety();

  return 0;
}

