/* ****************************************************************************
 * File Name   : lfu_cache.hpp
 * Author      : DaiDai
 * Mail        : daidai4269@aliyun.com
 * Created Time: 五  9/25 04:37:41 2020
 *************************************************************************** */

#ifndef __LFU_CACHE_HPP__
#define __LFU_CACHE_HPP__

#include <iostream>
#include <set>
#include <unordered_map>

// TODO
// https://www.nowcoder.com/questionTerminal/93aacb4a887b46d897b00823f30bfea1

template <typename KeyType, typename ValueType>
class LFUCache {
 public:
  LFUCache();
  ~LFUCache();

  void set(const KeyType& key, const ValueType& value);

  ValueType get(const KeyType& key);

 private:
};

template <typename KeyType, typename ValueType>
ValueType LFUCache::get(const KeyType& key) {
  return;
}

template <typename KeyType, typename ValueType>
void LFUCache::set(const KeyType& key, const ValueType& value) {
  //
}

#endif  // __LFU_CACHE_HPP__
