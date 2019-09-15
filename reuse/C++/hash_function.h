/* =============================================================================
> File Name: hash_function.h
> Author: DaiDai
> Mail: daidai4269@aliyun.com
> Created Time: Sun 15 Sep 2019 04:57:23 PM CST
============================================================================= */


/*
  TODO: not test, int function
  URL:
    [各种字符串Hash函数比较](https://www.byvoid.com/zhs/blog/string-hash-compare)
*/


#ifndef CC_HASH_FUNCTION_H
#define CC_HASH_FUNCTION_H


#define max_long_int 0x7FFFFFFF


#include <string>
#include <cstddef>


using std::string;


/*******************************************************************************
  string hash function
*******************************************************************************/


size_t SDBM_hash(const string& s) {
  size_t result = 0;
  for (char c : s)
    result = c + (result << 6) + (result << 16) - result;
  return result & max_long_int;
}

size_t RS_hash(const string& s) {
  unsigned int b = 378551;
  unsigned int a = 63689;
  size_t result = 0;
  for (char c : s) {
    result = result * a + c;
    a *= b;
  }
  return result & max_long_int;
}

size_t JS_hash(const string& s) {
  size_t result = 1315423911;
  for (char c : s)
    result ^= ((result << 5) + c + (result << 2));
  return result & max_long_int;
}

size_t PJW_hash() {
  size_t result = 0;
  return result & max_long_int;
}

size_t ELF_hash() {
  size_t result = 0;
  return result & max_long_int;
}

size_t BKDR_hash() {
  size_t result = 0;
  return result & max_long_int;
}

size_t DJB_hash() {
  size_t result = 0;
  return result & max_long_int;
}

size_t AP_hash() {
  size_t result = 0;
  return result & max_long_int;
}


/*******************************************************************************
  int hash function
*******************************************************************************/


#endif // CC_HASH_FUNCTION_H

