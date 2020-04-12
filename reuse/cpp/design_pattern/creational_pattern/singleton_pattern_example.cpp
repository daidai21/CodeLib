#include <iostream>


class Singleton {
 public:
  static Singleton* get_instance();

 private:
  Singleton() {}
  ~Singleton() {}

  Singleton(Singleton const&) = delete;
  Singleton& operator=(Singleton const&) = delete;

 private:
  static Singleton* instance;
};

Singleton* Singleton::get_instance() {
  if (instance == nullptr) {
    instance = new Singleton();
  }
  return instance;
}

Singleton* Singleton::instance = nullptr;


int main() {
  Singleton* s1 = Singleton::get_instance();
  Singleton* s2 = Singleton::get_instance();

  std::cout << s1 << std::endl;
  std::cout << s2 << std::endl;

  return 0;
}

