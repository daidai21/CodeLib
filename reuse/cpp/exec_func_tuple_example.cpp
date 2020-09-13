/* ****************************************************************************
 * File Name   : exec_func_tuple_example.cpp
 * Author      : DaiDai
 * Mail        : daidai4269@aliyun.com
 * Created Time: 日  9/13 14:45:41 2020
 *************************************************************************** */


#include "./exec_func_tuple.hpp"

#include <iostream>


using namespace std;


int add(int a, int b) {
  return a + b;
}


int main(int argc, char* argv[]) {
  std::tuple<int, int> t = std::make_tuple(1, 2);
  std::cout << exec_func_tuple(add, t) << std::endl;

  return 0;
}
