

// TODO: not test


#include <cassert>


// TODO
#define byte char

class BitMap {
 public:
  BitMap(long long int bits_num) {
    // check type convert overflow error
    assert(bits_num > 0);

    ptr_ = new char[sizeof(bits_num / 8 + 1)];
    // TODO: memset 0
    bits_num_ = bits_num;
  }

  ~BitMap() {
    if (ptr_ != nullptr)
        delete ptr_;
  }

  void set_true(long long int idx) {
    // check idx scope
    assert(idx > 0 && idx <= bits_num_);

    //
  }

  void set_false(long long int idx) {
    assert(idx > 0 && idx <= bits_num_);

    //
  }

  bool get(long long int idx) {
    assert(idx > 0 && idx <= bits_num_);

    //
  }

 private:
  unsigned long long int bits_num_;
  // bit array pointer
  char* ptr_;  // using char pointer because sizeof(char) is 1
};


