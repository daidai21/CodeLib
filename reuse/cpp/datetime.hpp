/* ****************************************************************************
 * File Name   : datetime.hpp
 * Author      : DaiDai
 * Mail        : daidai4269@aliyun.com
 * Created Time: 五  9/11 02:03:48 2020
 *************************************************************************** */


#include <iostream>



// TODO
// https://github.com/chxuan/cpp-utils/blob/master/DateTime/DateTime.hpp
// ERF: muduo, 

// https://www.runoob.com/cplusplus/cpp-date-time.html

enum weekday { sunday, monday, tuesday, wednesday, thursday, friday, saturday };
enum period { undefined, AM, PM };


class DateTime {
 public:
  DateTime(unsigned int year, unsigned int month, unsigned int day, 
           unsigned int hour, unsigned int minute, unsigned int second,
           unsigned int millisecond) {
    // check
    assert(year >= 1970);
    // TODO
  }

  DateTime() {}

 public:
  bool after(const DateTime& datetime);

  bool before(const DateTime& datetime);

  // cmp func operator


  int get_year();
  int get_month();
  int get_day();
  int get_hour();
  int get_minute();
  int get_second()l
  int get_millisecond();
  int get_microsecond();
  int get_nanosecond();
  int get_weekday();

 public:
  static long int get_curr_time_millis();

  std::string format(const std::string& str) {
    //
  }


};
