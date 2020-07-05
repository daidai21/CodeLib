// std::cref
// const reference

#include <iostream>
#include <functional>


void func(int& n1, const int& n2) {
  std::cout << "In function: " << n1 << " " << n2 << std::endl;
  n1++;
  // n2++; // compile error
}

int main(int argc, char* argv[]) {
  int n1 = 1;
  int n2 = 2;
  std::function<void()> bound_func = std::bind(func, n1, std::cref(n2));
  n1 = 10;
  n2 = 11;
  std::cout << "Before function: " << n1 << " " << n2 << std::endl;
  bound_func();
  std::cout << "After function: " << n1 << " " << n2 << std::endl;

  return 0;
}

