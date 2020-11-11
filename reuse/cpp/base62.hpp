/* ****************************************************************************
 * File Name   : base62.hpp
 * Author      : DaiDai
 * Mail        : daidai4269@aliyun.com
 * Created Time: 一 11/ 9 16:30:59 2020
 *************************************************************************** */

#ifndef __BASE62_HPP__
#define __BASE62_HPP__

#include <algorithm>
#include <string>

static const std::string BASE_62_CHAR = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

class Base62 {
 public:
  static std::string encode(unsigned long long int val) {
    std::string res;
    do {
      res.insert(0, std::string(1, BASE_62_CHAR[val % 62]));
      val /= 62;
    } while (val > 0);
    return res;
  }

  static unsigned long long int decode(std::string str) {
    std::reverse(str.begin(), str.end());
    unsigned long long int res = 0, cnt = 1;
    for (char ch : str) {
      res += BASE_62_CHAR.find(ch) * cnt;
      cnt *= 62;
    }
    return res;
  }
};

#endif  // __BASE62_HPP__
