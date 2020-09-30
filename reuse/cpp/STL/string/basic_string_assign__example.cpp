/* ****************************************************************************
 * File Name   : basic_string_assign__example.cpp
 * Author      : DaiDai
 * Mail        : daidai4269@aliyun.com
 * Created Time: 五  9/25 12:29:45 2020
 *************************************************************************** */


#include <iostream>
#include <string>


using namespace std;


int main(int argc, char* argv[]) {
  std::string s;

  s.assign(4, '=');
  std::cout << s << '\n';

  s.assign("C-style string", 7);
  std::cout << s << '\n';

  return 0;
}

