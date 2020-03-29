// TODO: http://harlon.org/2018/04/23/cpluscplusinteligenceptr/

#include <iostream>


class Parent;
class Child;


class Parent {
 public:
  Parent() {}
  ~Parent() {
    if (this->child != nullptr) {
      delete this->child;
      this->child = nullptr;
    }
  }

  void set_child(Child* child) {
    if (this->child != nullptr) {
      delete this->child;
    }
    this->child = child;
  }

 private:
  Child* child;
};

class Child {
 public:
  Child() {}
  ~Child() {
    if (this->parent != nullptr) {
      delete this->parent;
      this->parent = nullptr;
    }
  }

  void set_parent(Parent* parent) {
    if (this->parent != nullptr) {
      delete this->parent;
    }
    this->parent = parent;
  }

 private:
  Parent* parent;
};

int main() {
  Parent* parent = new Parent();
  Child*  child  = new Child();

  parent->set_child(child);
  child->set_parent(parent);

  delete parent;
  // delete child;

  return 0;
}
