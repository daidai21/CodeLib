#ifndef COPYABLE_AND_NONCOPYABLE_HPP__
#define COPYABLE_AND_NONCOPYABLE_HPP__


class Copyable {
 protected:
  Copyable() = default;
  ~Copyable() = default;
};


class NonCopyable {
 public:
  NonCopyable(const NonCopyable&) = delete;
  NonCopyable& operator=(const NonCopyable&) = delete;

 protected:
  NonCopyable() = default;
  ~NonCopyable() = default;
};


#endif // COPYABLE_AND_NONCOPYABLE_HPP__

