/* =============================================================================
> File Name: bloom_filter.h
> Author: DaiDai
> Mail: daidai4269@aliyun.com
> Created Time: Sat 14 Sep 2019 07:38:17 PM CST
============================================================================= */


/*
  TODO: not test
    how to class inherit delay?
*/


#ifndef CC_BLOOM_FILTER_H
#define CC_BLOOM_FILTER_H


#include <bitset>
#include <climits>
#include <cstdlib>
#include <functional>
#include <string>
#include <vector>
#include <cstdarg>
#include <cmath>


using std::size_t;
using std::string;


class BloomFilter {
 public:
  // add hash function to vector
  BloomFilter(size_t(*fmt)(string) ...) {
    va_list args;
    va_start(args, fmt);
    while (*fmt != '\0') {
      func_array_ptr.push_back(*fmt);
      va_arg(fmt, size_t(*)(string));
    }
  };

  ~BloomFilter() {};

  void add(string key) {
    ++insert_data_num;
    for (int i = 0; i < func_array_ptr.size(); ++i) {
        int index = (*func_array_ptr[i])(key);
        bit_array[index] = 1;
    }
  }

  // judge already add key
  bool had(string key) {
    for (int i = 0; i < func_array_ptr.size(); ++i) {
        int index = (*func_array_ptr[i])(key);
        if (!bit_array[index])
          return false;
    }
    return true;
  }

  float false_positive_rate() {
    return std::pow((1 - std::exp(- func_array_ptr.size() * insert_data_num / len_bitarray)), func_array_ptr.size());
  }

 private:
  // class private data
  size_t len_bitarray = INT_MAX;
  std::bitset<INT_MAX> bit_array;
  std::vector<size_t(*)(string)> func_array_ptr;
  size_t insert_data_num = 0;
};


#endif // CC_BLOOM_FILTER_H

