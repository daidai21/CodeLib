/* =============================================================================
> File Name: Exception.c
> Author: DaiDai
> Mail: daidai4269@aliyun.com
> Created Time: Wed 11 Sep 2019 07:15:13 PM CST
============================================================================= */


/*
  
  Reference:
    https://github.com/ThrowTheSwitch/CException
*/
// TODO


#include <stdio.h>
#include <errno.h>


// TODO:Exception
// goto
// jump
// exit()


int Exception() {}

/*
  http://baiy.cn/doc/cpp/inside_exception.htm

*/


#include <setjmp.h>

static jmp_buf s_jumpBuffer;

void Example() { 
  if (setjmp(s_jumpBuffer)) {
    // The longjmp was executed and returned control here
    printf("Exception happened here\n");
  } else {
    // Normal code execution starts here
    Test();
  }
}

void Test() {
  // Rough equivalent of `throw`
  longjmp(s_jumpBuffer, 42);
}

// https://stackoverflow.com/questions/10586003/try-catch-statements-in-c
