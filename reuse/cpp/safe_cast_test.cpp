/* ****************************************************************************
 * File Name   : safe_cast_test.cpp
 * Author      : DaiDai
 * Mail        : daidai4269@aliyun.com
 * Created Time: 五 11/ 6 18:43:29 2020
 *************************************************************************** */

#include "./safe_cast.hpp"

#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
  // TODO: random generate

  // convert to int
  std::string str = "1000";
  safe_cast<int>(str);

  // convert to long int
  safe_cast<long int>(str);

  // convert to long long int
  safe_cast<long long int>(str);

  // convert to double
  safe_cast<double>(str);

  // convert to float
  safe_cast<float>(str);

  // convert to bool
  safe_cast<bool>(str);

  // convert to string
  safe_cast<std::string>(str);

  return 0;
}
