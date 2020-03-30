#include <iostream>
#include <string>
#include <vector>
#include <utility>


int main(int argc, char* argv[]) {
  std::string str = "hello";
  std::vector<std::string> v;

  v.push_back(str);
  std::cout << "After copy, str is \"" << str << "\"" << std::endl;

  v.push_back(std::move(str));
  std::cout << "After move, str is \"" << str << "\"" << std::endl;

  std::cout << "The contents of the vector are \"" << v[0] << "\", \"" << v[1] << std::endl;

  return 0;
}

