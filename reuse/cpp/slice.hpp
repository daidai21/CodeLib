/* ****************************************************************************
 * File Name   : slice.hpp
 * Author      : DaiDai
 * Mail        : daidai4269@aliyun.com
 * Created Time: 四  9/24 19:04:55 2020
 *************************************************************************** */

#ifndef __SLICE_HPP__
#define __SLICE_HPP__

#include <string>

class Slice {
 public:
  Slice() : data_(""), size_(0) {}

  Slice(const char* d, size_t n) : data_(d), size_(n) {}

  Slice(const std::string& s) : data_(s.data()), size_(s.size()) {}

  Slice(const char* s) : data_(s), size_(strlen(s)) {}

  Slice(const Slice&) = default;
  Slice& operator=(const Slice&) = default;

  inline const char* data() const {
    return data_;
  }

  inline size_t size() const {
    return size_;
  }

  bool empty() const {
    return size_ == 0;
  }

  char operator[](size_t n) const {
    assert(n < size_);
    return data_[n];
  }

  void clear() {
    data_ = "";
    size_ = 0;
  }

  void remove_prefix(size_t n) {
    assert(n <= size_);
    data_ += n;
    size_ -= n;
  }

  std::string to_string() const {
    return std::string(data_, size_);
  }

  bool starts_with(const Slice& x) {
    return ((size_ > x.size()) && (memcmp(data_, x.data_, x.size_) == 0));
  }

  inline int compare(const Slice& x) const {
    const size_t min_len = (size_ < x.size_) ? size_ : x.size_;
    int ret = memcmp(data_, x.data_, min_len);
    if (ret == 0) {
      if (size_ < x.size_) {
        ret = -1;
      } else if (size_ > x.size_) {
        ret += 1;
      }
    }
    return ret;
  }

 private:
  const char* data_;
  size_t size_;
};

inline bool operator==(const Slice& x, const Slice& y) {
  return ((x.size() == y.size()) &&
          (memcmp(x.data(), y.data(), x.size()) == 0));
}

inline bool operator!=(const Slice& x, const Slice& y) {
  return !(x == y);
}

#endif  // __SLICE_HPP__
