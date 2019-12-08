/* =============================================================================
> File Name: using_two_int_record_one_long_int.cpp
> Author: DaiDai
> Mail: daidai4269@aliyun.com
> Created Time: Sun 08 Dec 2019 03:57:01 PM CST
============================================================================= */


#include <iostream>
#include <utility>
#include <tuple>
#include <bitset>


using namespace std;


pair<int, int> change_longint_to_int(long int val) {
  
  return make_pair(
    static_cast<int>(val >> 32),
    static_cast<int>(val & 0xffffffff));
}


long int change_int_to_longint(int v1, int v2) {
  long int val;
  val = v1;
  val <<= 32;
  val += v2;
  return val;
}


int main() {
  long int val = 1234567890123456789;
  int v1, v2;
  tie(v1, v2) = change_longint_to_int(val);
  cout << val << " --> " << v1 <<  "+" << v2 << endl;

  bitset<64> tmp(val);
  cout << tmp << endl;
  bitset<32> tmp1(v1), tmp2(v2);
  cout << tmp1 << "" << tmp2 << endl;


  val = change_int_to_longint(v1, v2);
  cout << v1 <<  "+" << v2 << " --> " << val << endl;

  return 0;
}

