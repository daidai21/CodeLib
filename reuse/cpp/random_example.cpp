/* ****************************************************************************
 * File Name   : random_example.cpp
 * Author      : DaiDai
 * Mail        : daidai4269@aliyun.com
 * Created Time: 六 11/ 7 16:45:44 2020
 *************************************************************************** */

#include <iostream>

#include "./random.hpp"

using namespace std;

int main(int argc, char* argv[]) {
  Random rand();

  cout << rand.randint(1, 10) << endl;
  cout << rand.randbool() << endl;
  cout << rand.randrange(0, 10, 2) << endl;
  cout << rand.uniform(1.1, 10.4) << endl;
  return 0;
}
