/* =============================================================================
> File Name: MaxMinStack_example.cpp
> Author: DaiDai
> Mail: daidai4269@aliyun.com
> Created Time: Wed 11 Dec 2019 01:00:48 PM CST
============================================================================= */


#include "MaxMinStack.hpp"

#include <iostream>

using namespace std;


int main() {
  MaxStack<int> ms;
  ms.push(1);
  cout << ms.get_max() << endl;
  ms.push(2);
  cout << ms.get_max() << endl;
  ms.pop();
  cout << ms.get_max() << endl;
  ms.push(234);
  cout << ms.get_max() << endl;
  ms.push(122);
  cout << ms.get_max() << endl;
  ms.pop();
  cout << ms.get_max() << endl;
  ms.push(234);
  cout << ms.get_max() << endl;
  ms.push(122);
  cout << ms.get_max() << endl;

  return 0;
}

