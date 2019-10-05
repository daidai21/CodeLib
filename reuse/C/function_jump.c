/* =============================================================================
> File Name: function_jump.c
> Author: DaiDai
> Mail: daidai4269@aliyun.com
> Created Time: Mon 16 Sep 2019 07:41:13 PM CST
============================================================================= */


/*
  URL:
    https://www.runoob.com/cprogramming/c-macro-setjmp.html
*/


#include <stdio.h>
#include <setjmp.h>


static jmp_buf buf;


void func1() {
  printf("func1\n");
  longjmp(buf, 1);  // jump to function setjmp() and setjmp return 1
}


void func2() {
  func1();
  printf("func2\n");
}


int main() {
  if (!setjmp(buf))
    func2();
  else
    printf("main\n");

  return 0;
}
