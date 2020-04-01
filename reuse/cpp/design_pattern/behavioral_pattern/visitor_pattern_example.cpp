#include <iostream>
#include <vector>


class Computer;
class Mouse;
class Keyboard;
class Monitor;


// visitor interface
class ComputerPartVisitor {
 public:
  virtual void visit(Computer* c) = 0;
  virtual void visit(Mouse* m) = 0;
  virtual void visit(Keyboard* k) = 0;
  virtual void visit(Monitor* m) = 0;
};


// interface
class ComputerPart {
 public:
  virtual void accept(ComputerPartVisitor* cpv) = 0;
};


// entity class
class Keyboard: public ComputerPart {
 public:
  virtual void accept(ComputerPartVisitor* cpv) {
    cpv->visit(this);
  }
};

class Monitor: public ComputerPart {
 public:
  virtual void accept(ComputerPartVisitor* cpv) {
    cpv->visit(this);
  }
};

class Mouse: public ComputerPart {
 public:
  virtual void accept(ComputerPartVisitor* cpv) {
    cpv->visit(this);
  }
};

class Computer: public ComputerPart {
 public:
  Computer() {
    this->parts = {new Mouse(), new Keyboard(), new Monitor()};
  }

  ~Computer() {
    for (int i = 0; i < this->parts.size(); ++i) {
      delete this->parts[i];
    }
    // or
    // delete this->parts[0];
    // delete this->parts[1];
    // delete this->parts[2];
  }
  virtual void accept(ComputerPartVisitor* cpv) {
    for (int i = 0; i < this->parts.size(); ++i) {
      this->parts[i]->accept(cpv);
    }
    cpv->visit(this);
  }

 private:
  std::vector<ComputerPart* > parts;
};


// create entity visitor class
class ComputerPartDisplayVisitor: public ComputerPartVisitor {
 public:
  virtual void visit(Computer* c) {
    std::cout << "Display Computer." << std::endl;
  }

  virtual void visit(Mouse* m) {
    std::cout << "Display Mouse." << std::endl;
  }

  virtual void visit(Keyboard* k) {
    std::cout << "Display Keyboard." << std::endl;
  }

  virtual void visit(Monitor* m) {
    std::cout << "Display Monitor." << std::endl;
  }
};


// using visitor pattern example
int main() {
  ComputerPart* computer = new Computer();
  computer->accept(new ComputerPartDisplayVisitor());

  delete computer;

  return 0;
}

