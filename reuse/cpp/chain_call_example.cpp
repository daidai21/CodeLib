#include <iostream>


// TODO: template <typename ValType>


class NumberRef {
 public:
  NumberRef() {}
  NumberRef(int val) {
    this->val = val;
  }
  ~NumberRef() {}

  // opt: +-*/
  NumberRef& add(int val) {
    this->val += val;
    return *this;
  }

  NumberRef& subtract(int val) {
    this->val -= val;
    return *this;
  }

  NumberRef& multiply(int val) {
    this->val *= val;
    return *this;
  }

  NumberRef& divide(int val) {
    this->val /= val;
    return *this;
  }

  // IO opt
  void print() {
    std::cout << this->val << std::endl;
  }

  int get_val() {
    return this->val;
  }

  void set_val(int val) {
    this->val = val;
  }

 private:
  int val;
};

class NumberPtr {
 public:
  NumberPtr() {}
  NumberPtr(int val) {
    this->val = val;
  }
  ~NumberPtr() {}

  // opt: +-*/
  NumberPtr* add(int val) {
    this->val += val;
    return this;
  }

  NumberPtr* subtract(int val) {
    this->val -= val;
    return this;
  }

  NumberPtr* multiply(int val) {
    this->val *= val;
    return this;
  }

  NumberPtr* divide(int val) {
    this->val /= val;
    return this;
  }

  // IO opt
  void print() {
    std::cout << this->val << std::endl;
  }

  int get_val() {
    return this->val;
  }

  void set_val(int val) {
    this->val = val;
  }

 private:
  int val;
};


int main() {
  NumberRef num(1);
  num.add(1);
  num.print();
  num.divide(2);
  num.print();
  num.multiply(4);
  num.print();
  num.add(1).subtract(10);
  num.print();
  num.subtract(5).print();

  std::cout << "*****" << std::endl;

  NumberPtr* n = new NumberPtr(2);
  n->add(1)->print();

  return 0;
}
