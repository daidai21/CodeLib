/* =============================================================================
> File Name: C++/lambda.cc
> Author: DaiDai
> Mail: daidai4269@aliyun.com
> Created Time: Wed 11 Sep 2019 03:37:03 PM CST
============================================================================= */


/*
  lambda function
  Compile command:
    g++ lambda.cc -I ../../third_party/cxx-prettyprint;./a.out
*/


#include "prettyprint.hpp"

#include <iostream>
#include <typeinfo>
#include <vector>
#include <algorithm>
using namespace std;


int main(){
  int x = 1, y = 2;
  cout << typeid(y).name() << " " << typeid(y).name() << endl;

  auto i1 = [] (int x, int y) -> int { return x + y; };
  cout << i1 << " " << typeid(i1).name() << endl;
  auto i2 = [] (int x, int y) { return x + y; };
  cout << i2 << " " << typeid(i2).name() << endl;
  auto i3 = [] (int x, int y) { return x + y; };
  cout << i3 << " " << typeid(i3).name() << endl;

  vector<int> vec = {1, 2, 3, 4, 4, 2, 312, 1, 23, 1234, 456};
  sort(vec.begin(), vec.end(), i2);
  for(int v : vec)
    cout << v << " ";
  cout << endl;

  sort(vec.begin(), vec.end(), [](int& a, int& b) {
    return a > b;
  });
  for(int v : vec)
    cout << v << " ";
  cout << endl;

  cout << "++++++++++++++++++++++++++++++++" << endl;
  cout << vec << endl;

  vector<vector<int>> v2d = {
    {1, 2, 3, 4},
    {1, 123425}
  };
  cout << "++++++++++++++++++++++++++++++++" << endl;
  cout << v2d << endl;

}
