/* =============================================================================
> File Name: is_prime.hpp
> Author: DaiDai
> Mail: daidai4269@aliyun.com
> Created Time: Tue 24 Dec 2019 10:35:12 PM CST
============================================================================= */


#include <cmath>


bool is_prime(int n) {
  if (n < 2)
    return false;
  else if (n == 2)
    return true;
  for (int i = 2; i <= std::sqrt(n); ++i) {
    if (n % i == 0)
      return false;
  }
  return true;
}

