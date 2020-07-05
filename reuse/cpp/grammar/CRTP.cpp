// Curiously Recurring Template Pattern


#include <iostream>
#include <vector>


class Animal {
 public:
  virtual ~Animal() {}

  virtual void say() const = 0;
};

template <typename T>
class Animal_CRTP: public Animal {
 public:
  void say() const override {
    static_cast<const T*>(this)->say();
  }
};

class Cat: public Animal_CRTP<Cat> {
 public:
  void say() const {
    std::cout << "Meow~ I'm a cat." << std::endl;
  }
};

class Dog: public Animal_CRTP<Dog> {
 public:
  void say() const {
    std::cout << "Wang~ I'm a dog." << std::endl;
  }
};

int main(int argc, char* argv[]) {
  std::vector<Animal*> zoo;
  zoo.push_back(new Cat());
  zoo.push_back(new Dog());

  for (auto it = zoo.begin(); it != zoo.end(); ++it) {
    (*it)->say();
  }

  for (auto it = zoo.begin(); it != zoo.end(); ++it) {
    delete (*it);
  }

  return 0;
}

