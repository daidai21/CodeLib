#include <string>
#include <algorithm>

#include <cassert>
#include <iostream>


const std::string BASE_62_CHAR = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";


std::string to_base62(unsigned long long int val) {
  std::string res;
  do {
    res.insert(0, std::string(1, BASE_62_CHAR[val % 62]));
    val /= 62;
  } while (val > 0);
  return res;
}

unsigned long long int to_base10(std::string str) {
  std::reverse(str.begin(), str.end());
  unsigned long long int res = 0, cnt = 1;
  for (char ch : str) {
    res += BASE_62_CHAR.find(ch) * cnt;
    cnt *= 62;
  }
  return res;
}


int main() {
  std::cout << to_base62(12233) << std::endl;
  assert("3bj" == to_base62(12233));
  assert(12233 == to_base10("3bj"));

  return 0;
}
