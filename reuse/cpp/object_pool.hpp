/* ****************************************************************************
 * File Name   : object_pool.hpp
 * Author      : DaiDai
 * Mail        : daidai4269@aliyun.com
 * Created Time: 五  9/11 02:23:11 2020
 *************************************************************************** */

#ifndef __OBJECT_POOL_HPP__
#define __OBJECT_POOL_HPP__

#include <functional>
#include <memory>
#include <vector>

template <typename ObjectType>
class ObjectPool {
 public:
  using DeleterType = std::function<void(ObjectType*)>;

  void add(std::unique_ptr<ObjectType> t) {
    pool.emplace_back(std::move(t));
  }

  std::unique_ptr<ObjectType, DeleterType> get() {
    if (pool.empty()) {
      throw std::logic_error("No more object");
    }

    std::unique_ptr<ObjectType, DeleterType> ptr(pool.back().release(), [this](ObjectType* t) {
      pool.emplace_back(std::unique_ptr<ObjectType>(t));
    });
    pool.pop_back();
    return std::move(ptr);
  }

  std::shared_ptr<ObjectType> get_shared() {
    if (pool.empty()) {
      throw std::logic_error("No more object");
    }
    auto pin = std::unique_ptr<ObjectType>(std::move(pool.back()));
    pool.pop_back();
    return std::shared_ptr<ObjectType>(pin.release(), [this](ObjectType* t) {
      pool.emplace_back(std::unique_ptr<ObjectType>(t));
    });
  }

  bool empty() const {
    return pool.empty();
  }

  unsigned int size() const {
    return pool.size();
  }

 private:
  std::vector<std::unique_ptr<ObjectType>> pool;
};

#endif  // __OBJECT_POOL_HPP__
