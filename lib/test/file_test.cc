/* =============================================================================
> File Name: file_test.cc
> Author: DaiDai
> Mail: daidai4269@aliyun.com
> Created Time: Mon 23 Dec 2019 09:25:56 PM CST
============================================================================= */

#include "../src/file.h"

#include <iostream>

using namespace std;
using namespace file;

int main() {
  File f;
  f.open("asdsad.txt", "wb");
  f.write("asdasdadfa\n");
  f.close();


}
