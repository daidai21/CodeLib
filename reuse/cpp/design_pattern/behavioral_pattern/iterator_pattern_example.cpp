#include <iostream>
#include <vector>
#include <string>


// create interface
class Iterator {
 public:
  virtual bool has_next() = 0;
  virtual void first() = 0;
  virtual void next() = 0;
  virtual std::string curr_item() = 0;
};

class Container {
 public:
  virtual Iterator* create_iterator() = 0;
};

// entity class
class ConcreteContainer;
class ConcreteIterator: public Iterator {
 public:
  ConcreteIterator(ConcreteContainer* cc) : cc(cc), idx(0) { }

  virtual void first() { this->idx = 0; }

  virtual void next() { this->idx++; }

  virtual bool has_next();

  virtual std::string curr_item();

 private:
  ConcreteContainer* cc;
  unsigned int       idx;
};

class ConcreteContainer: public Container {
 public:
  ConcreteContainer(std::vector<std::string>& names) : names(names) { }

  Iterator* create_iterator();

  unsigned int size() { return this->names.size(); }

  std::string at(unsigned int idx) { return this->names[idx]; }

 private:
  std::vector<std::string> names;
};

bool ConcreteIterator::has_next() { return this->idx < this->cc->size(); }

std::string ConcreteIterator::curr_item() {
  if (this->has_next()) {
    return this->cc->at(idx);
  }
  return NULL;
}

Iterator* ConcreteContainer::create_iterator() { return new ConcreteIterator(this); }


// using iterator pattern example
int main() {
  std::vector<std::string> names = {"Robert" , "John" ,"Julie" , "Lora"};
  ConcreteContainer* names_container = new ConcreteContainer(names);
  
  for (Iterator* it = names_container->create_iterator(); it->has_next(); it->next()) {
    std::cout << it->curr_item() << std::endl;
  }
  
  delete names_container;

  return 0;
}
