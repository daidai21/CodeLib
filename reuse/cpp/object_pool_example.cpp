/* ****************************************************************************
 * File Name   : object_pool_example.cpp
 * Author      : DaiDai
 * Mail        : daidai4269@aliyun.com
 * Created Time: 三 11/11 22:40:59 2020
 *************************************************************************** */

#include <iostream>

#include "./object_pool.hpp"

using namespace std;

class A {
 public:
  void print() {
    std::cout << "Hello world" << std::endl;
  }
};

int main(int argc, char* argv[]) {
  ObjectPool<A> pool;
  pool.add(std::unique_ptr<A>(new A()));
  pool.add(std::unique_ptr<A>(new A()));
  std::cout << "Object pool size: " << pool.size() << std::endl;

  {
    auto a = pool.get();
    a->print();
    pool.get();
    std::cout << "Object pool size: " << pool.size() << std::endl;
  }

  std::cout << "Object pool size: " << pool.size() << std::endl;

  return 0;
}
