#include <vector>
#include <stdexcept>
#include <iostream>



// reference:
// https://www.boost.org/doc/libs/1_36_0/libs/dynamic_bitset/dynamic_bitset.html
// https://zh.cppreference.com/w/cpp/container/vector




// API like std::vector
class BitVector {
  // member function
 public:
  explicit BitVector(const BitVector&);
  explicit BitVector(const std::vector<bool>&);
  explicit BitVector(const unsigned int&);
  explicit BitVector(const unsigned long int&);
  explicit BitVector(const unsigned long long int&);

  ~BitVector() {}

  void operator=(const BitVector&);

  void assign(const unsigned long long int& len, const char& ch);

  // element access
 public:
  bool at(const unsigned long long int& idx);

  bool BitVector::operator[](const unsigned long long int& idx);

  bool front() const;

  bool back() const;

  // capacity
 public:
  bool empty() const;

  unsigned long long int size() const;

  unsigned long long int max_size() const;

  void reserve(const long long int& new_cap);

  unsigned long long int capacity() const;

  void shrink_to_fit();

  // modifier
 public:
  void clear(); // cap is not change

  void insert(const unsigned long long int&, const bool&);

  void erase(const unsigned long long&);

  void push_back(const bool&);

  void pop_back();

  void resize(const unsigned long long&);

  // non-member function
 public:
  bool operator==(const BitVector&) const;

  void swap(BitVector&);

  // self define
 public:
  void print();

 private:
  std::vector<char>      vec_ch_;
  unsigned long long int bits_len_;

};

// member function
////////////////////////////////////////////////////////////////////////////////
BitVector::BitVector(const BitVector& bv) {
  this->vec_ch_   = bv.vec_ch_;
  this->bits_len_ = bv.bits_len_;
}

BitVector::BitVector(const std::vector<bool>& vec_bool) {
  int need_char_len = vec_bool.size() / 8 + (vec_bool.size() % 8) > 0;
  this->vec_ch_.resize(need_char_len);
  // 
}

BitVector::BitVector(const unsigned int& bits_len) {
  this->bits_len_ = bits_len;
  unsigned int need_char_len = bits_len / 8 + (bits_len % 8) > 0;
  this->vec_ch_.resize(need_char_len);
}

BitVector::BitVector(const unsigned long int& bits_len) {
  this->bits_len_ = bits_len;
  unsigned long int need_char_len = bits_len / 8 + (bits_len % 8) > 0;
  this->vec_ch_.resize(need_char_len);
}

BitVector::BitVector(const unsigned long long int& bits_len) {
  this->bits_len_ = bits_len;
  unsigned long long int need_char_len = bits_len / 8 + (bits_len % 8) > 0;
  this->vec_ch_.resize(need_char_len);
}

void BitVector::operator=(const BitVector& bv) {
  this->vec_ch_   = bv.vec_ch_;
  this->bits_len_ = bv.bits_len_;
}

void BitVector::assign(const unsigned long long int& len, const char& ch) {
  for (int i = 0; i < len; ++i) {
    //
  }
}

// element access
////////////////////////////////////////////////////////////////////////////////
bool BitVector::at(const unsigned long long int& idx) {
  if (idx >= 0 && idx < this->bits_len_) {
    std::invalid_argument("BitVector::at() idx arg err");
  }

  return (this->vec_ch_[idx / 8] & (1 << idx % 8)) != 0;
}

// BUG
bool BitVector::operator[](const unsigned long long int& idx) {
  if (idx >= 0 && idx < this->bits_len_) {
    std::invalid_argument("BitVector::operator[] idx arg err");
  }

  return (this->vec_ch_[idx / 8] & (1 << idx % 8)) != 0;
}

bool BitVector::front() const {
  if (this->bits_len_ == 0) {
    // TODO
  }
  return this->at(0);
}

bool BitVector::back() const {
  if (this->bits_len_ == 0) {
    // TODO
  }
  return this->at(this->bits_len_ - 1);
}

// capacity
////////////////////////////////////////////////////////////////////////////////
bool BitVector::empty() const {
  return this->bits_len_ == 0;
}

unsigned long long int BitVector::size() const {
  return this->bits_len_;
}

unsigned long long int BitVector::max_size() const {
  return this->vec_ch_.max_size() * 8;
}

void BitVector::reserve(const long long int& new_cap) {
  int new_vec_ch_len = new_cap / 8 + (new_cap % 8) > 0;
  this->vec_ch_.reserve(new_vec_ch_len);
  if (new_vec_ch_len < this->bits_len_) {
    std::invalid_argument("BitVector::reserve() new_cap arg err");
  }
}

unsigned long long int BitVector::capacity() const {
  return this->vec_ch_.capacity() * 8;
}

void BitVector::shrink_to_fit() {
  this->vec_ch_.shrink_to_fit();
}

// modifier
////////////////////////////////////////////////////////////////////////////////
void BitVector::clear() {
  for (int i = 0; i < this->vec_ch_.size(); ++i) {
    this->vec_ch_[i] = 0;
  }
  this->bits_len_ = 0;
}

void BitVector::insert(const unsigned long long int& idx, const bool& val) {
  if (this->bits_len_ + 1 <= this->vec_ch_.size() * 8) {
    this->vec_ch_.resize(this->vec_ch_.size() + 1);
  }
  // move forward
  for (int i = this->bits_len_; i > idx; --i) {
    this[i] = this[i - 1];
  }
  // BUG
  this->at(idx) = val;
  this->bits_len_++;
}

void BitVector::erase(const unsigned long long& idx) {
  //
}

void BitVector::push_back(const bool& val) {
  //
}

void BitVector::pop_back() {
  this->bits_len_--;
}

void BitVector::resize(const unsigned long long& new_cap) {
  int new_vec_ch_len = new_cap / 8 + (new_cap % 8) > 0;
  this->vec_ch_.reserve(new_vec_ch_len);
  if (new_vec_ch_len < this->bits_len_) {
    std::invalid_argument("BitVector::reserve() new_cap arg err");
  }
}

// non-member function
////////////////////////////////////////////////////////////////////////////////
bool BitVector::operator==(const BitVector& bv) const {
  return this->bits_len_ == bv.bits_len_ && this->vec_ch_ == bv.vec_ch_;
}

void BitVector::swap(BitVector& bv) {
  std::vector<char> temp_vec_ch = bv.vec_ch_;
  bv.vec_ch_    = this->vec_ch_;
  this->vec_ch_ = temp_vec_ch;
  unsigned long long int temp_bits_len = bv.bits_len_;
  bv.bits_len_    = this->bits_len_;
  this->bits_len_ = temp_bits_len;
}

// self define
////////////////////////////////////////////////////////////////////////////////
void BitVector::print() {
  std::cout << "[";
  for (int i = 0; i < this->bits_len_; ++i) {
    std::cout << this->at(i) << ", ";
  }
  std::cout << "]" << std::endl;
}
