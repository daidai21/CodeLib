#include <iostream>
#include <memory>


struct Foo: public std::enable_shared_from_this<Foo> {
 public:
  Foo() { std::cout << "Foo::Foo()" << std::endl; }
  ~Foo() { std::cout << "Foo::~Foo()" << std::endl; }
  std::shared_ptr<Foo> get_Foo() {
    return std::enable_shared_from_this<Foo>::shared_from_this();
  }
};


int main(int argc, char* argv[]) {
  Foo* f = new Foo;
  std::shared_ptr<Foo> pf1;
  {
    std::shared_ptr<Foo> pf2(f);
    pf1 = pf2->get_Foo();
  }
  std::cout << "pf2 is gone" << std::endl;

  return 0;
}

