// reference links:
// https://github.com/caozhiyi/Base/blob/master/TimeTool.h
// https://github.com/chenshuo/muduo/blob/master/muduo/base/Timestamp.h
// https://github.com/chenshuo/muduo/blob/master/muduo/base/Date.h


#ifndef __TIMESTAMP_HPP__
#define __TIMESTAMP_HPP__


#ifdef DEBUG
#  include <iostream>
#endif


// TODO
// not support thread safe
class Timestamp {
 public:
  Timestamp();
  Timestamp(const Timestamp& t);
  ~Timestamp();

  int get_year();
  int get_month();
  int get_weekday();
  int 

  // operator
  bool operator==();
  

 private:
  uint64_t now;
};


#endif // __TIMESTAMP_HPP__

