/* ****************************************************************************
 * File Name   : any_type.hpp
 * Author      : DaiDai
 * Mail        : daidai4269@aliyun.com
 * Created Time: 五  9/11 01:43:51 2020
 *************************************************************************** */


#ifndef __ANY_TYPE_HPP__
#define __ANY_TYPE_HPP__


#include <iostream>
#include <memory>
#include <typeindex>


// TODO
// https://github.com/chxuan/cpp-utils/blob/master/Any/Any.hpp

class AnyType {
 public:
  AnyType();

 private:
  class BaseType;

  using BaseTypePtr = std::unique_ptr<BaseType>;

  class BaseType {
   public:
    virtual ~BaseType() {}

    virtual BaseType clone() const = 0;
  };


};




#endif // __ANY_TYPE_HPP__
