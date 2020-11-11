/* ****************************************************************************
 * File Name   : base64_test.cpp
 * Author      : DaiDai
 * Mail        : daidai4269@aliyun.com
 * Created Time: 一 11/ 9 16:33:42 2020
 *************************************************************************** */

#include "./base64.hpp"

#include <iostream>
#include <string>

int main() {
  //

  std::string s = "q23";


  Base64::decode(s);

  return 0;
}
