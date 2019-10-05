/* =============================================================================
> File Name: bit_array.h
> Author: DaiDai
> Mail: daidai4269@aliyun.com
> Created Time: Sat 14 Sep 2019 10:43:45 PM CST
============================================================================= */


/*
  TODO: binary pointer
  URL:
    [std::bitset](https://zh.cppreference.com/w/cpp/utility/bitset)
*/


#ifndef CC_BIT_ARRAY_H
#define CC_BIT_ARRAY_H


#include <cstddef>
#include <bitset>


using std::size_t;


class BitArray {
  BitArray() {
    *ptr = new 
  }
  BitArray(const int N) {
    *ptr = new std::bitset<N>;
  }
  ~BitArray() {
    delete ptr;
    delete ptr_;
  }

  bool any() {
    return *ptr.any();
  }

  bool none() {
    return *ptr.none();
  }

  size_t count() {
    return *ptr.count();
  }

  void set() {
    *ptr.set();
  }

  void reset() {
    *ptr.reset();
  }

  void flip() {
    *ptr.flip();
  }


  bool& operator[](size_t pos) {
    // TODO
  }

  void _resize(const size_t n) {
    // TODO
  }

 private:
  std::bitset<8>* ptr, * ptr_;
  size_t size = 8;
};

#endif // CC_BIT_ARRAY_H

