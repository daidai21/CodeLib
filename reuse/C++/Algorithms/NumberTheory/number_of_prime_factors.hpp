/* =============================================================================
> File Name: number_of_prime_factors.hpp
> Author: DaiDai
> Mail: daidai4269@aliyun.com
> Created Time: Tue 24 Dec 2019 10:37:24 PM CST
============================================================================= */


#include "is_prime.hpp"


int prime_factors_num(int n) {
  int cnt = 0;
  for (int i = 1; i <= n; ++i) {
    if (n % i == 0 && is_prime(i)) {
      cnt++;
    }
  }
  return cnt;
}

