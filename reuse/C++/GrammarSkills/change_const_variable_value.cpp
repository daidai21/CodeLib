/* =============================================================================
> File Name: change_const_variable_value.cpp
> Author: DaiDai
> Mail: daidai4269@aliyun.com
> Created Time: Sat 23 Nov 2019 10:59:43 PM CST
============================================================================= */


#include <iostream>

using namespace std;


int main() {
  int var = 1;
  int *p = &var;
  *p = 2;
  cout << var << endl;

  return 0;
}
