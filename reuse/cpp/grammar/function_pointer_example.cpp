/* ****************************************************************************
 * File Name   : function_pointer_example.cpp
 * Author      : DaiDai
 * Mail        : daidai4269@aliyun.com
 * Created Time: 三  7/15 17:39:10 2020
 *************************************************************************** */


#include <iostream>


using namespace std;


typedef void(*pFun)(int);


void func(int a) {
  cout << a << endl;
}


int main() {
  pFun p = func;
  (*p)(2);

  return 0;
}

