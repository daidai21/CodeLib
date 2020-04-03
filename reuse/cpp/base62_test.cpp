#include "base62.hpp"

#include <cassert>
#include <iostream>


int main() {
  std::cout << to_base62(12233) << std::endl;
  assert("3bj" == to_base62(12233));
  assert(12233 == to_base10("3bj"));

  return 0;
}

