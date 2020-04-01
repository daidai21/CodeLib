#include <iostream>
#include <string>
#include <vector>


// abstract class
class AbstractCustomer {
 public:
  virtual bool is_null() = 0;
  virtual std::string get_name() = 0;

 protected:
  std::string name;
};


// entity class with abstract class
class RealCustomer: public AbstractCustomer {
 public:
  RealCustomer(std::string name) : name(name) { }

  virtual std::string get_name() {
    return this->name;
  }

  virtual bool is_null() {
    return false;
  }

 private:
  std::string name;
};


class NullCustomer: public AbstractCustomer {
 public:
  virtual std::string get_name() {
    return "Not Available in Customer Database.";
  }

  virtual bool is_null() {
    return true;
  }
};


// factory class
class CustomerFactory {
 public:
  AbstractCustomer* get_customer(std::string name) {
    for (int i = 0; i < this->names.size(); ++i) {
      if (this->names[i] == name) {
        return new RealCustomer(name);
      }
    }
    return new NullCustomer();
  }

 private:
  std::vector<std::string> names = {"Rob", "Joe", "Julie"};
};


// using null object design pattern example
int main() {
  CustomerFactory customer_factory;
  AbstractCustomer* customer1 = customer_factory.get_customer("Rob");
  AbstractCustomer* customer2 = customer_factory.get_customer("Bob");
  AbstractCustomer* customer3 = customer_factory.get_customer("Julie");
  AbstractCustomer* customer4 = customer_factory.get_customer("Laura");

  std::cout << "Customers" << std::endl;
  std::cout << customer1->get_name() << std::endl;
  std::cout << customer2->get_name() << std::endl;
  std::cout << customer3->get_name() << std::endl;
  std::cout << customer4->get_name() << std::endl;

  delete customer1;
  delete customer2;
  delete customer3;
  delete customer4;

  return 0;
}

