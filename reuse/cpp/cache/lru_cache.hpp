/* =============================================================================
> File Name: lru_cache.hpp
> Author: DaiDai
> Mail: daidai4269@aliyun.com
> Created Time: Sun 03 Nov 2019 10:21:10 PM CST
============================================================================= */


#ifndef LRU_CACHE_HPP__
#define LRU_CACHE_HPP__


#include <iostream>
#include <list>
#include <unordered_map>


template <typename TypeKey, typename TypeValue>
class LRUCache {
  typedef typename std::list<TypeValue>::iterator ListTypeValueIterator;

 public:
  LRUCache() {}
  LRUCache(unsigned int size) : capacity(size) {}
  ~LRUCache() {}

  void put(const TypeKey& key, const TypeValue& value) {
    // TODO: control capacity
    if (unordered_map_.find(key) == unordered_map_.end()) {
      list_.push_front(value);
      ListTypeValueIterator it = list_.begin();
      unordered_map_[key] = it;
    } else {
      list_.erase(unordered_map_[key]);
      list_.push_front(value);
      ListTypeValueIterator it = list_.begin();
      unordered_map_[key] = it;
    }
  }

  TypeValue get(const TypeKey& key) {
    if (unordered_map_.find(key) == unordered_map_.end())
      return {};
    else { // TODO: node move to head
      return *(unordered_map_[key]);
    }
  }

  bool exits(const TypeKey& key) {
    return unordered_map_.find(key) != unordered_map_.end();
  }

 private:
  int capacity = -1;
  std::list<TypeValue> list_;
  std::unordered_map<TypeKey, ListTypeValueIterator> unordered_map_;
};


#endif // LRU_CACHE_HPP__
