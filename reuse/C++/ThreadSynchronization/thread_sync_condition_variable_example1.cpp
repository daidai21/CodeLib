/* =============================================================================
> File Name: thread_sync_condition_variable_example1.cpp
> Author: DaiDai
> Mail: daidai4269@aliyun.com
> Created Time: Thu 12 Dec 2019 04:56:50 PM CST
============================================================================= */


// condition_variable


#include <iostream>
#include <thread>
#include <condition_variable>
#include <mutex>

using namespace std;


mutex mtx;
condition_variable cv;

bool data_ready{ false };


void waiting_for_work() {
  cout << "waitting" << endl;
  unique_lock<mutex> lck(mtx);
  cv.wait(lck, [] { return data_ready; });
  cout << "running" << endl;
}


void set_data_ready() {
  {
    lock_guard<mutex> lck(mtx);
    data_ready = true;
  }
  cout << "data prepared" << endl;
  cv.notify_one();
}


int main() {
  thread t1(waiting_for_work);
  thread t2(set_data_ready);

  t1.join();
  t2.join();

  return 0;
}

