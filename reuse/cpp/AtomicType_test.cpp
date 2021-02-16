/* ****************************************************************************
 * File Name   : AtomicType_test.cpp
 * Author      : DaiDai
 * Mail        : daidai4269@aliyun.com
 * Created Time: 二  2/16 16:32:41 2021
 *************************************************************************** */

#include "./AtomicType.hpp"

#include <iostream>
#include <string>

using namespace std;

void unittest(bool judge, std::string msg) {
  if (judge) {
    cout << "[unittest] [ok] " << msg << endl;
  } else {
    cout << "[unittest] [err] " << msg << endl;
    assert(false);
  }
}

int main(int argc, char* argv[]) {
  // test: init
  AtomicType<int> at_int0;
  unittest((at_int0.get() == 0), "at_int0.get() == 0");

  AtomicType<int> at_int1(1);
  unittest((at_int1.get() == 1), "at_int1.get() == 1");

  // test: get set = ++ --
  unittest((at_int0.get() == 0), "at_int0.get() == 0");

  at_int0.set(2);
  unittest((at_int0.get() == 2), "at_int0.get() == 2");

  at_int0 = 3;
  unittest((at_int0.get() == 3), "at_int0.get() == 3");

  // test: ++i --i i++ i--
  at_int0++;
  unittest((at_int0.get() == 4), "at_int0.get() == 4");

  at_int0--;
  unittest((at_int0.get() == 3), "at_int0.get() == 3");

  // test: == != > < >= <=
  // TODO

  // test: inc dec
  AtomicType<int> at_int2(3);
  unittest((at_int2.get() == 3), "at_int2.get() == 3");

  at_int2.inc();
  unittest((at_int2.get() == 4), "at_int2.get() == 4");

  at_int2.dec();
  unittest((at_int2.get() == 3), "at_int2.get() == 3");

  // test: add sub
  at_int2.add(4);
  unittest((at_int2.get() == 7), "at_int2.get() == 7");

  at_int2.sub(5);
  unittest((at_int2.get() == 2), "at_int2.get() == 2");

  // test: 
  at_int1.inc_and_get();
  unittest((at_int1.get() == 2), "at_int1.get() == 2");

  at_int1.dec_and_get();
  unittest((at_int1.get() == 1), "at_int1.get() == 1");

  at_int1.add_and_get(2);
  unittest((at_int1.get() == 3), "at_int1.get() == 3");

  at_int1.sub_and_get(3);
  unittest((at_int1.get() == 0), "at_int1.get() == 0");

  unittest((at_int1.get_and_inc() == 0), "at_int1.get_and_inc() == 0");
  unittest((at_int1.get() == 1), "at_int1.get() == 1");

  unittest((at_int1.get_and_dec() == 1), "at_int1.get_and_dec() == 1");
  unittest((at_int1.get() == 0), "at_int1.get() == 0");

  unittest((at_int1.get_and_add(4) == 0), "at_int1.get_and_add(4) == 0");
  unittest((at_int1.get() == 4), "at_int1.get() == 4");

  unittest((at_int1.get_and_sub(5) == 4), "at_int1.get_and_sub(4) == 4");
  unittest((at_int1.get() == -1), "at_int1.get() == -1");



  return 0;
}
