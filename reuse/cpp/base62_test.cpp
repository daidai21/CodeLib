#include "base62.hpp"

#include <cassert>
#include <iostream>


int main() {
  std::cout << Base62::encode(12233) << std::endl;
  assert("3bj" == Base62::encode(12233));
  assert(12233 == Base62::decode("3bj"));

  return 0;
}
