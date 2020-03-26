/* =============================================================================
> File Name: exchange_str_char_type.cpp
> Author: DaiDai
> Mail: daidai4269@aliyun.com
> Created Time: Mon 23 Dec 2019 03:13:53 AM CST
============================================================================= */


#include <stdio.h>
#include <string.h>

#include <iostream>
#include <string>

using namespace std;


// char* -> std::string
void char_ptr_to_string() {
  string s = "123456";
  const char* ch = s.data();
  cout << *ch << endl;
  printf("%s\n", ch);
}

// std::string
void string_to_char_ptr() {
  const char* ch = "123134124";
  // string s(ch, strlen(ch));
  string s(ch);
  cout << s << endl;
}

// char [];
// TODO

int main() {
  char_ptr_to_string();

  string_to_char_ptr();

  return 0;
}

