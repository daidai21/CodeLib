/* =============================================================================
> File Name: Singletion_test.cpp
> Author: DaiDai
> Mail: daidai4269@aliyun.com
> Created Time: Sun 03 Nov 2019 08:12:46 PM CST
============================================================================= */


#include "Singletion.hpp"

#include <iostream>


using namespace std;


int main() {
  cout << &(Singletion::get_instance()) << endl;

  return 0;
}

