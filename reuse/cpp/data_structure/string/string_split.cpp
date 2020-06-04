#include <vector>
#include <string>
#include <iostream>
#include <algorithm>


std::vector<std::string> split(std::string& str, const std::string sep) {
  std::vector<std::string> res;
  std::size_t pos = 0;
  while ((pos = str.find(sep)) != std::string::npos) {
    res.push_back(str.substr(0, pos));
    str.erase(0, pos + sep.size());
  }
  res.push_back(str);
  return res;
}


int main() {
  std::string s = "scott>=tiger>=mushroom";
  std::string delimiter = ">=";

  auto output = split(s, delimiter);
  for (auto line : output) {
    std::cout << line << std::endl;
  }

  return 0;
}
