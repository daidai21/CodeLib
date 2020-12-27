/* ****************************************************************************
 * File Name   : BaseAspect_example.cpp
 * Author      : DaiDai
 * Mail        : daidai4269@aliyun.com
 * Created Time: 三 12/23 16:25:35 2020
 *************************************************************************** */

#include <iostream>

#include "./BaseAspect.hpp"

template <class T>
class LogAspect : public BaseAspect<T> {
  const char* m_name;

 public:
  LogAspect(T* pT, const char* name = "")
      : BaseAspect<T>(pT), m_name(name) {
    std::cout << "LogAspect: " << m_name << " begin" << std::endl;
  }

  ~LogAspect() {
    std::cout << "LogAspect: " << m_name << " end" << std::endl;
  };
};

class Action {
 public:
  void Say(const char* str) {
    std::cout << "Action::Say( " << str << " )" << std::endl;
  }
};

int main(int argc, char* argv[]) {
  Action a;
  LogAspect<Action>(&a, "Action::Say")->Say("Hi");

  std::cout << std::endl;
  return 0;
}
