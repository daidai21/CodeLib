/* =============================================================================
> File Name: thread.cpp
> Author: DaiDai
> Mail: daidai4269@aliyun.com
> Created Time: Thu 12 Sep 2019 09:20:26 PM CST
============================================================================= */


#include <iostream>
#include <thread>


using namespace std;


void hello() {
  cout << "hello" << endl;
}

int main() {
  thread t(hello);
  t.join();
  cout << "over" << endl;

  return 0;
}
