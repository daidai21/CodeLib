// TODO: memory leak

#include <iostream>


// interface
class Strategy {
 public:
  virtual int operation(int n1, int n2) = 0; // pure virtual function
};

// define three algorithms
class OperationAdd: public Strategy {
 public:
  virtual int operation(int n1, int n2) {
    return n1 + n2;
  }
};

class OperationSubtract: public Strategy {
 public:
  virtual int operation(int n1, int n2) {
    return n1 - n2;
  }
};

class OperationMultiply: public Strategy {
 public:
  virtual int operation(int n1, int n2) {
    return n1 * n2;
  }
};

// context object
class Context {
 public:
  Context(Strategy* strategy) {
    this->strategy = strategy;
  }

  ~Context() {
    delete this->strategy;
  }

  int execute(int n1, int n2) {
    return this->strategy->operation(n1, n2);
  }

 private:
  Strategy* strategy;
};

// using strategy pattern example
int main() {
  Context* context = new Context(new OperationAdd());
  std::cout << "10 + 5 = " << context->execute(10, 5) << std::endl;

  context = new Context(new OperationSubtract());
  std::cout << "10 - 5 = " << context->execute(10, 5) << std::endl;

  context = new Context(new OperationMultiply());
  std::cout << "10 * 5 = " << context->execute(10, 5) << std::endl;

  delete context;

  return 0;
}
