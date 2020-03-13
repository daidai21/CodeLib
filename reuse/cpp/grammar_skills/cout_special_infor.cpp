/* =============================================================================
> File Name: cout_special_infor.cpp
> Author: DaiDai
> Mail: daidai4269@aliyun.com
> Created Time: Thu 26 Dec 2019 02:18:58 PM CST
============================================================================= */


#include <iostream>

using namespace std;

int main() {
  // number
  cout << 0x0 << endl;
  cout << 0x1 << endl;

  cout << 0xbc9f1d34 << endl; // 16 binary
  cout << 0xffffffffU << endl;

  // string
  cout << "\\x00" << endl;
  cout << "\\x0b" << endl;

  cout << "\x00" << endl;
  cout << "\x0b" << endl;

  // sizeof
  cout << "\\x00" << " --> " << "\x00" << " --sizeof--> " << sizeof("\x00") << endl;
  cout << sizeof(void* ) << endl;
  cout << sizeof(size_t) << endl;

  return 0;
}



