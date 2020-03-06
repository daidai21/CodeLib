/* =============================================================================
> File Name: BitMap.hpp
> Author: DaiDai
> Mail: daidai4269@aliyun.com
> Created Time: Sat 11 Jan 2020 00:07:52 AM CST
============================================================================= */


// TODO: not test


#include <cassert>


// TODO
#define byte char

class BitMap {
 public:
  BitMap(long long int bits_num) {
    // check type convert overflow error
    assert(bits_num > 0);

    ptr_ = new char[sizeof(bits_num / 8 + 1)];
    // TODO: memset 0
    bits_num_ = bits_num;
  }

  ~BitMap() {
    if (ptr_ != nullptr)
        delete ptr_;
  }

  void set_true(long long int idx) {
    // check idx scope
    assert(idx > 0 && idx <= bits_num_);

    //
  }

  void set_false(long long int idx) {
    assert(idx > 0 && idx <= bits_num_);

    //
  }

  bool get(long long int idx) {
    assert(idx > 0 && idx <= bits_num_);

    //
  }

 private:
  unsigned long long int bits_num_;
  // bit array pointer
  char* ptr_;  // using char pointer because sizeof(char) is 1
};


// reference:
// https://www.boost.org/doc/libs/1_36_0/libs/dynamic_bitset/dynamic_bitset.html
// https://zh.cppreference.com/w/cpp/container/vector
class BitMapVector {
 public:
  BitMapVector() {}
  ~BitMapVector() {}

  // operator=
  // operator[]
  bool at() {}

  // empty
  // size
  // max_size
  // reserve
  // capacity

  // push_back
  // pop_back

 private:
  //
};
