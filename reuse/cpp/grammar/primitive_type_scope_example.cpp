/* ****************************************************************************
 * File Name   : primitive_type_scope_example.cpp
 * Author      : DaiDai
 * Mail        : daidai4269@aliyun.com
 * Created Time: 二  2/23 15:40:27 2021
 *************************************************************************** */
#include <iostream>
#include <limits>
#include <limits.h>

using namespace std;

int main() {
  cout << LLONG_MIN << endl;
  cout << LONG_MIN << endl;

  /**
    Going by the standard, all that's guaranteed is:
      int must be at least 16 bits
      long must be at least 32 bits
      long long must be at least 64 bits
    On major 32-bit platforms:
      int is 32 bits
      long is 32 bits as well
      long long is 64 bits
    On major 64-bit platforms:
      int is 32 bits
      long is either 32 or 64 bits
      long long is 64 bits as well
  */

  //
  // 

  cout << "type: \t\t"
       << "************size**************" << endl;
  cout << "bool: \t\t"
       << "所占字节数：" << sizeof(bool);
  cout << "\t最大值：" << (numeric_limits<bool>::max)();
  cout << "\t\t最小值：" << (numeric_limits<bool>::min)() << endl;
  cout << "char: \t\t"
       << "所占字节数：" << sizeof(char);
  cout << "\t最大值：" << (numeric_limits<char>::max)();
  cout << "\t\t最小值：" << (numeric_limits<char>::min)() << endl;
  cout << "signed char: \t"
       << "所占字节数：" << sizeof(signed char);
  cout << "\t最大值：" << (numeric_limits<signed char>::max)();
  cout << "\t\t最小值：" << (numeric_limits<signed char>::min)() << endl;
  cout << "unsigned char: \t"
       << "所占字节数：" << sizeof(unsigned char);
  cout << "\t最大值：" << (numeric_limits<unsigned char>::max)();
  cout << "\t\t最小值：" << (numeric_limits<unsigned char>::min)() << endl;
  cout << "wchar_t: \t"
       << "所占字节数：" << sizeof(wchar_t);
  cout << "\t最大值：" << (numeric_limits<wchar_t>::max)();
  cout << "\t\t最小值：" << (numeric_limits<wchar_t>::min)() << endl;
  cout << "short: \t\t"
       << "所占字节数：" << sizeof(short);
  cout << "\t最大值：" << (numeric_limits<short>::max)();
  cout << "\t\t最小值：" << (numeric_limits<short>::min)() << endl;
  cout << "int: \t\t"
       << "所占字节数：" << sizeof(int);
  cout << "\t最大值：" << (numeric_limits<int>::max)();
  cout << "\t最小值：" << (numeric_limits<int>::min)() << endl;
  cout << "unsigned: \t"
       << "所占字节数：" << sizeof(unsigned);
  cout << "\t最大值：" << (numeric_limits<unsigned>::max)();
  cout << "\t最小值：" << (numeric_limits<unsigned>::min)() << endl;
  cout << "long: \t\t"
       << "所占字节数：" << sizeof(long);
  cout << "\t最大值：" << (numeric_limits<long>::max)();
  cout << "\t最小值：" << (numeric_limits<long>::min)() << endl;
  cout << "unsigned long: \t"
       << "所占字节数：" << sizeof(unsigned long);
  cout << "\t最大值：" << (numeric_limits<unsigned long>::max)();
  cout << "\t最小值：" << (numeric_limits<unsigned long>::min)() << endl;
  cout << "double: \t"
       << "所占字节数：" << sizeof(double);
  cout << "\t最大值：" << (numeric_limits<double>::max)();
  cout << "\t最小值：" << (numeric_limits<double>::min)() << endl;
  cout << "long double: \t"
       << "所占字节数：" << sizeof(long double);
  cout << "\t最大值：" << (numeric_limits<long double>::max)();
  cout << "\t最小值：" << (numeric_limits<long double>::min)() << endl;
  cout << "float: \t\t"
       << "所占字节数：" << sizeof(float);
  cout << "\t最大值：" << (numeric_limits<float>::max)();
  cout << "\t最小值：" << (numeric_limits<float>::min)() << endl;
  cout << "size_t: \t"
       << "所占字节数：" << sizeof(size_t);
  cout << "\t最大值：" << (numeric_limits<size_t>::max)();
  cout << "\t最小值：" << (numeric_limits<size_t>::min)() << endl;
  cout << "string: \t"
       << "所占字节数：" << sizeof(string) << endl;
  cout << "long long int: \t"
       << "所占字节数：" << sizeof(long long int);
  cout << "\t最大值：" << (numeric_limits<long long int>::max)();
  cout << "\t最小值：" << (numeric_limits<long long int>::min)() << endl;
  cout << "long int: \t"
       << "所占字节数：" << sizeof(long int);
  cout << "\t最大值：" << (numeric_limits<long int>::max)();
  cout << "\t最小值：" << (numeric_limits<long int>::min)() << endl;

  // << "\t最大值：" << (numeric_limits<string>::max)() << "\t最小值：" << (numeric_limits<string>::min)() << endl;
  cout << "type: \t\t"
       << "************size**************" << endl;
  return 0;
}
