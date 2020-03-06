/* =============================================================================
> File Name: os_test.cc
> Author: DaiDai
> Mail: daidai4269@aliyun.com
> Created Time: Mon 23 Dec 2019 08:59:45 PM CST
============================================================================= */

#include "../src/os.h"

#include <iostream>
#include <thread>

#include <sys/sysinfo.h>

using namespace std;

int main() {
  cout <<thread::hardware_concurrency() << endl;

  //
  struct sysinfo infor;
  if ( sysinfo(&infor) == -1)
    return 0;
  cout << infor.totalram << endl;

  cout << os::mem_size() << endl;
}

