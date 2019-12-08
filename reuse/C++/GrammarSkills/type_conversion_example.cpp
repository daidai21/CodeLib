/* =============================================================================
> File Name: type_conversion_example.cpp
> Author: DaiDai
> Mail: daidai4269@aliyun.com
> Created Time: Sun 08 Dec 2019 07:57:42 PM CST
============================================================================= */


#include <string>
#include <iostream>
#include <typeinfo>

using namespace std;


int main() {
  int n = 12345;
  string s = to_string(n);
  cout << typeid(n).name() << " --> " << typeid(s).name() << " :  " << n << " --> " << s << endl;

  n = atoi(s.c_str());
  cout << typeid(s).name() << " --> " << typeid(n).name() << " :  " << s << " --> " << n << endl;

  n = stoi(s);
  cout << typeid(s).name() << " --> " << typeid(n).name() << " :  " << s << " --> " << n << endl;

  long int n1 = stol(s);
  cout << typeid(s).name() << " --> " << typeid(n1).name() << " :  " << s << " --> " << n1 << endl;

  long long int n2 = stoll(s);
  cout << typeid(s).name() << " --> " << typeid(n2).name() << " :  " << s << " --> " << n2 << endl;

  return 0;
}

