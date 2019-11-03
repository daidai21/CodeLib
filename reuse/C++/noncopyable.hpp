/* =============================================================================
> File Name: noncopyable.hpp
> Author: DaiDai
> Mail: daidai4269@aliyun.com
> Created Time: Wed 09 Oct 2019 09:17:06 PM CST
============================================================================= */



#ifndef NONCOPYABLE_H_
#define NONCOPYABLE_H_


class noncopyable {
 public:
  noncopyable(const noncopyable&) = delete;
  void operator=(const noncopyable&) = delete;

 protected:
  noncopyable() = default;
  ~noncopyable() = default;
}


#endif // NONCOPYABLE_H_
