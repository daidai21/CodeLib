/* ****************************************************************************
 * File Name   : safe_cast.hpp
 * Author      : DaiDai
 * Mail        : daidai4269@aliyun.com
 * Created Time: 五  9/11 02:39:02 2020
 *************************************************************************** */

// TODO
// https://github.com/chxuan/cpp-utils/blob/master/lexical_cast/lexical_cast.h
// not test
// add unsigned type
// type convert have missing

#ifndef __SAFE_CAST_HPP__
#define __SAFE_CAST_HPP__

#include <string>

template <typename FromType, typename ToType>
struct converter {};

// convert to int
template <typename FromType>
struct converter<int, FromType> {
 public:
  static int convert(const std::string& from) {
    return std::atoi(from.c_str());
  }

  static int convert(const char* from) {
    return std::atoi(from);
  }
};

// convert to long int
template <typename FromType>
struct converter<long int, FromType> {
 public:
  static long int convert(const std::string& from) {
    return std::atol(from.c_str());
  }

  static long int convert(const char* from) {
    return std::atol(from);
  }
};

// convert to long long int
template <typename FromType>
struct converter<long long int, FromType> {
 public:
  static long long int convert(const std::string& from) {
    return std::atoll(from.c_str());
  }

  static long long int convert(const char* from) {
    return std::atoll(from);
  }
};

// convert to double
template <typename FromType>
struct converter<double, FromType> {
 public:
  static double convert(const std::string& from) {
    return std::atof(from.c_str());
  }

  static double convert(const char* from) {
    return std::atof(from);
  }
};

// convert to float
template <typename FromType>
struct converter<float, FromType> {
 public:
  static double convert(const std::string& from) {
    return static_cast<float>(std::atof(from.c_str()));
  }

  static double convert(const char* from) {
    return static_cast<float>(std::atof(from));
  }
};

// convert to bool
template <typename FromType>
struct converter<bool, FromType> {
 public:
  static bool convert(int from) {
    return from > 0 ? true : false;
  }

  static bool convert(const std::string& from) {
    return std::atoi(from.c_str()) > 0 ? true : false;
  }
};

// convert to std::string
template <typename FromType>
struct converter<std::string, FromType> {
 public:
  static std::string convert(int from) {
    return std::to_string(from);
  }

  static std::string convert(double from) {
    return std::to_string(from);
  }

  static std::string convert(float from) {
    return std::to_string(from);
  }

  static std::string convert(const std::string& from) {
    return from;
  }

  static std::string convert(const char* from) {
    return from;
  }

  static std::string convert(char from) {
    return std::string(&from);
  }
};

// simple convert
template <typename ToType, typename FromType>
ToType safe_cast(const FromType& from) {
  return converter<ToType, FromType>::convert(from);
}

#endif  // __SAFE_CAST_HPP__
