/* ****************************************************************************
 * File Name   : literal_operator_example.cpp
 * Author      : DaiDai
 * Mail        : daidai4269@aliyun.com
 * Created Time: 一  2/15 02:16:44 2021
 *************************************************************************** */

/**
 * 字面量
 * c++11支持为内置类型提供新的自定义字面量的形式
 * 称为literal operator，字面量运算符
 */
#include <iostream>

#include <cstddef>

using namespace std;



constexpr size_t KiB = 1024;
constexpr size_t MiB = 1024 * KiB;
constexpr size_t GiB = 1024 * MiB;

constexpr size_t operator"" _KiB(unsigned long long val) { return val * KiB; }
constexpr size_t operator"" _MiB(unsigned long long val) { return val * MiB; }
constexpr size_t operator"" _GiB(unsigned long long val) { return val * GiB; }



int main(int argc, char* argv[]) {

  cout <<  1_KiB << endl;
  cout <<  1_MiB << endl;
  cout <<  1_GiB << endl;

  return 0;
}
