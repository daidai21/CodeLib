/* =============================================================================
> File Name: async_cout_example.cpp
> Author: DaiDai
> Mail: daidai4269@aliyun.com
> Created Time: Mon 23 Dec 2019 10:12:46 PM CST
============================================================================= */


#include <iostream>
#include <thread>
#include <future>

using namespace std;


int main() {
  cout << "1" << endl;
  auto f1 = async( []{ cout << "hello1" << endl; });
  cout << "2" << endl;

  cout << "+++++" << endl;
  cout << "1" << endl;
  auto f2 = async( []{ cout << "hello2" << endl; });
  f2.wait();
  cout << "2" << endl;


  cout << "+++++" << endl;
  cout << "1" << endl;
  thread t( []{ cout << "hello3" << endl; });
  t.join();
  cout << "1" << endl;

  return 0;
}
