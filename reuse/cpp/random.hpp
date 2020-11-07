/* =============================================================================
> File Name: random.hpp
> Author: DaiDai
> Mail: daidai4269@aliyun.com
> Created Time: Mon 09 Dec 2019 11:03:45 AM CST
============================================================================= */

#ifndef DAIDAI_RANDOM_HPP_
#define DAIDAI_RANDOM_HPP_

#include <chrono>
#include <random>
#include <vector>

class Random {
 public:
  Random() {
    seed_ = std::chrono::high_resolution_clock::now().time_since_epoch().count();
    engine_.seed(seed_);
  }

  Random(long long int seed) {
    seed_ = seed;
    engine_.seed(seed_);
  }

  int randint(int start, int end) {
    std::uniform_int_distribution<int> res(start, end);
    return res(engine_);
  }

  bool randbool() {
    return randint(0, 1) == 1 ? true : false;
  }

  double uniform(double start, double end) {
    std::uniform_int_distribution<double> res(start, end);
    return res(engine_);
  }

  template <typename Type>
  Type choice(const std::vector<Type>& arr) {
    int idx = randint(0, arr.size() - 1);
    return arr[idx];
  }

  char choice(const std::string& arr) {
    int idx = randint(0, arr.size() - 1);
    return arr[idx];
  }

  int randrange(int start, int end, int step) {
    std::vector<int> tmp;
    for (int i = start; i < end; i += step) {
      tmp.push_back(i);
    }
    int idx = randint(0, tmp.size() - 1);
    return tmp[idx];
  }

  template <typename Type>
  void shuffle(std::vector<Type>& arr) { // FIXME: array...
    std::shuffle(arr.begin(), arr.end(), engine_);
  }

  template <typename Type>
  std::vector<Type> sample(const std::vector<Type>& arr, int num) {
    std::vector<Type> res(num);
    for (int i = 0; i < num; ++i) {
      res[i] = choice(arr);
    }
    return res;
  }

  std::string sample(const std::string& arr, int num) {
    std::string res;
    for (int i = 0; i < num; ++i) {
      res.push_back(choice(arr));
    }
    return res;
  }

 private:
  std::default_random_engine engine_;
  long long int seed_;
};

#endif  // DAIDAI_RANDOM_HPP_
