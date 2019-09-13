# [C++ Project Guide]()

```cpp
// xxx.h

#ifdef __WIN32__
...
#ifdef __LINUX__
...
#endif
```

```cpp
#if defined(WIN32) || defined(_WIN32) || defined(WIN64) || defined(_WIN64)
#include <windows.h>
#elif !defined(__unix)
#define __unix
#endif

#ifdef __unix
#include <unistd.h>
#include <sys/time.h>
#include <sys/wait.h>
#include <sys/types.h>
#endif


  #if defined(__unix)
    // unix
  #else
    // win32
  #endif

```

### Basic deveplopment Tool

- `Cmake / make / makefile`

### Catelog

Google search: cpp project template

### Code style check

- `glog`
- `gflags`
- [`cpplint.py`](https://github.com/google/styleguide)
gprof
valgrind
update-alternatives
### Code test

- `gdb` trace qire
- vcpkg
- sanitizer `g++ xxx.cc -fsanitize=selection`
    - memory
    - address
    - thread

***


```cpp
/* =============================================================================
> File Name: xxx.h
> Author: DaiDai
> Mail: daidai4269@aliyun.com
> Created Time: Wed 04 Sep 2019 07:46:16 PM CST
============================================================================= */


#ifndef XXX_H
#define XXX_H


#define 

const int var1;


extern int var2

template <classname T>
class Class {
 public:
  Class();
  ~Class();

  inline void func1() {
    // add code
  }

  void func2();

  // TODO: static const

 private:
  int var1 = 3;
  int var2;

}


class Class {
 public:
  Class();
  ~Class();

  inline void func1() {
    // add code
  }

  void func2();

  // TODO: static const

 private:
  int var1 = 3;
  int var2;

}


int func1();

inline int func2() {
  // add code
}


#endif
```

```cpp
/* =============================================================================
> File Name: xxx.c
> Author: DaiDai
> Mail: daidai4269@aliyun.com
> Created Time: Wed 04 Sep 2019 07:46:16 PM CST
============================================================================= */




```
