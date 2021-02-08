/* ****************************************************************************
 * File Name   : raw_string.cpp
 * Author      : DaiDai
 * Mail        : daidai4269@aliyun.com
 * Created Time: 五  2/ 5 17:19:29 2021
 *************************************************************************** */

#include <iostream>
#include <string>

using namespace std;

/**
 * raw string: 不会对反斜杠'\'进行特殊的转义处理。
 * raw string literals
 */

int main(int argc, char* argv[]) {
  // 一个普通的字符串，'\n'被当作是转义字符，表示一个换行符。
  std::string normal_str = "First line.\nSecond line.\nEnd of message.\n";
  // 一个raw string，'\'不会被转义处理。因此，"\n"表示两个字符：字符反斜杠 和 字母n。
  // 注意其语法格式，稍后会介绍C++ 11中为什么会采用这种语法格式来表达一个raw string。
  std::string raw_str = R"(First line.\nSecond line.\nEnd of message.\n)";

  std::cout << normal_str << std::endl;
  std::cout << raw_str << std::endl;
  std::cout << R"foo(Hello, world!)foo" << std::endl;

  // raw string可以跨越多行，其中的空白和换行符都属于字符串的一部分。
  std::cout << R"(
                   Hello,
                   world!
                   )"
            << std::endl;


  std::cout << R"(")" << std::endl; // 输出一个双引号："
  std::cout << R"delimiter()")delimiter" << std::endl; // 输出：)"

  return 0;
}
