/* =============================================================================
> File Name: xxx.h
> Author: DaiDai
> Mail: daidai4269@aliyun.com
> Created Time: Thu 12 Sep 2019 04:39:14 PM CST
============================================================================= */


#ifndef TEMPLATE_XXX_H
#define TEMPLATE_XXX_H


#include <vector>


namespace xxx {


const int var1;

extern int var2;

template <typename T>
class Class1 {
 public:
  Class1();
  ~Class1();

  inline void func1() {
    // add code
  }

  static int a = 2;
  const int a = 2;

 private:
  int var1 = 3;
  int var2;

};

class Class2 {
 public:
  Class2();
  ~Class2();

  inline void func1() {
    // add code
  }

  void func2();

  static int a2;
  const int a = 2;

 private:
  int var1 = 3;
  int var2;

};

int func1();

inline int func2() {
  // add code
}

} // namespace xxx


#endif
