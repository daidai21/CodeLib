/* =============================================================================
> File Name: MonotonicStack_example.cpp
> Author: DaiDai
> Mail: daidai4269@aliyun.com
> Created Time: Thu 05 Dec 2019 10:19:38 PM CST
============================================================================= */


#include "MonotonicStack.hpp"

#include <iostream>

using namespace std;


int main() {
  MonotonicStack ms;

  ms.push(1);
  ms.display();
  ms.push(4);
  ms.display();
  ms.push(3);
  ms.display();
  ms.push(45);
  ms.display();
  ms.push(9);
  ms.push(90);
  ms.push(900);
  ms.push(19);
  ms.push(20);
  ms.push(1000);
  cout << ms.top() << endl;
  cout << ms.pop() << endl;
  ms.display();

  cout << "+++++" << endl;
  MonotonicStack ms2;
  ms2.display();
  ms2.push(1);
  ms2.display();
  ms2.push(3);
  ms2.display();
  ms2.push(5);
  ms2.push(10);
  ms2.push(30);
  ms2.push(50);
  ms2.display();
  ms2.push(20);
  ms2.display();

  return 0;
}

