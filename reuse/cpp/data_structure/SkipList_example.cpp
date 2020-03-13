/* =============================================================================
> File Name: SkipList_example.cpp
> Author: DaiDai
> Mail: daidai4269@aliyun.com
> Created Time: Mon 02 Dec 2019 09:29:11 PM CST
============================================================================= */


#include "SkipList.hpp"

#include <iostream>


using namespace std;


int main() {
  SkipList sl(5);
  sl.insert(1, 2);
  sl.display();

  return 0;
}
