/* =============================================================================
> File Name: lru_cache_test.cpp
> Author: DaiDai
> Mail: daidai4269@aliyun.com
> Created Time: Sun 03 Nov 2019 10:35:28 PM CST
============================================================================= */


/*
  Fibonacci
*/


#include "./lru_cache.hpp"

#include <iostream>
#include <ctime>
#include <chrono>


using namespace std;


// not used cache
long long int fibonacci(long long int n) {
  if (n <= 0)
    return 0;
  else if (n == 1 || n == 2)
    return 1;
  else
    return fibonacci(n - 2) + fibonacci(n - 1);
}

// used cache and not config capacity of Cache
long long int fibonacci_cache(long long int n, LRUCache<int, long long int>& lru) {
  if (lru.exits(n))
    return lru.get(n);
  else if (n <= 0)
    return 0;
  else if (n == 1 || n == 2) {
    lru.put(n, 1);
    return 1;
  } else {
    long long int ans = fibonacci_cache(n - 2, lru) + fibonacci_cache(n - 1, lru);
    lru.put(n, ans);
    return ans;
  }
}

// used cache, config capacity of Cache
// TODO

int main() {
  LRUCache<int, long long int> lru;
  auto T1 = chrono::system_clock::now();
  cout << fibonacci(45) << endl;
  auto T2 = chrono::system_clock::now();
  cout << "Time: " << (T2 - T1).count() << endl;
  cout << fibonacci_cache(45, lru) << endl;
  auto T3 = chrono::system_clock::now();
  cout << "Time: " << (T3 - T2).count() << endl;

  // LRUCache<int, int> lru(5);
  // lru.put(1, 1);
  // lru.put(2, 1);
  // lru.put(2, 2);
  // cout << lru.get(1) << endl;
  // cout << lru.get(2) << endl;

  // std::list<int>::iterator it;
  // cout << typeid(it).name() << endl;
  // std::list<int> l;
  // cout << typeid(l.begin()).name() << endl;

  return 0;

}
