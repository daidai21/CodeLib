/* ****************************************************************************
 * File Name   : BaseAspect.hpp
 * Author      : DaiDai
 * Mail        : daidai4269@aliyun.com
 * Created Time: 三 12/23 16:25:21 2020
 *************************************************************************** */

#ifndef __BaseAspect_HPP__
#define __BaseAspect_HPP__

template <class T>
class BaseAspect {
  T* m_pT;

 protected:
  BaseAspect(T* pT)
      : m_pT(pT) {
  }

  virtual ~BaseAspect() {
  }

 public:
  T* operator->() {
    return m_pT;
  }
};

#endif  // __BaseAspect_HPP__
