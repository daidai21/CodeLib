#include <iostream>


class Foo {
 public:
  void infor() {
    std::cout << "Foo::infor()" << std::endl;
  }

  class Bar {
   public:
    void infor() {
        std::cout << "Bar::infor()" << std::endl;
    }
  };
};


class Class1 {
 public:
  void infor() {
    std::cout << "Class1::infor()" << std::endl;
  }

  class Class2 {
   public:
    void infor() {
        std::cout << "Class1::Class2::infor()" << std::endl;
    }

    class Class3 {
     public:
      void infor() {
        std::cout << "Class1::Class2::Class3::infor()" << std::endl;
      }
    };
  };
};


int main() {
  Foo foo;
  foo.infor();
  Foo::Bar bar;
  bar.infor();

  Class1 c1;
  c1.infor();
  Class1::Class2 c2;
  c2.infor();
  Class1::Class2::Class3 c3;
  c3.infor();

  return 0;
}
