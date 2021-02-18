/* ****************************************************************************
 * File Name   : judge_function_defined.c
 * Author      : DaiDai
 * Mail        : daidai4269@aliyun.com
 * Created Time: 四  2/18 15:19:51 2021
 *************************************************************************** */

/**
 * Weak Symbol 弱符号
 * 
 * 确定函数是否定义了
 */

#include <stdio.h>

/* weak declaration must always be present */
void func_show1(char* str) __attribute__((weak));

void func_show1(char* str) {
  printf("%s\n", str);
}

void func_show2(char* str) __attribute__((weak));

// void func_show2(char* str) {
//   printf("%s\n", str);
// }

int main() {
  if (func_show1) {
    func_show1("func_show1() defined");
  } else {
    printf("func_show1() not defined\n");
  }

  if (func_show2) {
    func_show2("func_show2() defined");
  } else {
    printf("func_show2() not defined\n");
  }

  return 0;
}
