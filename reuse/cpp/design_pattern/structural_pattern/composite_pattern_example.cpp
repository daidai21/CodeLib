#include <iostream>
#include <vector>
#include <string>


// create employee class
class Employee {
 public:
  Employee(std::string name, std::string dept, int salary) : name(name), dept(dept), salary(salary) { }

  void add(Employee* e) {
    this->subordinates.push_back(e);
  }

  void remove(Employee* e) {
    // remove e
    for (int i = 0; i < this->subordinates.size(); ++i) {
      this->subordinates.erase(this->subordinates.begin() + i);
      return ;
    }
  }

  std::vector<Employee* > get_subordinates() {
    return this->subordinates;
  }

  std::string to_str() {
    return "Employee: [Name: " + this->name + ", " +
                       "dept: " + this->dept + ", " +
                       "salary: " + std::to_string(this->salary) + "]";
  }

 private:
  std::string             name;
  std::string             dept;
  int                     salary;
  std::vector<Employee* > subordinates;
};


// using composite pattern example
int main() {
  Employee* CEO              = new Employee("John", "CEO", 30000);
  Employee* head_sales       = new Employee("Robert", "Head Sales", 20000);
  Employee* head_marketing   = new Employee("Michel", "Head Marketing", 20000);
  Employee* clerk1           = new Employee("Laura", "Marketing", 10000);
  Employee* clerk2           = new Employee("Bob", "Marketing", 10000);
  Employee* sales_executive1 = new Employee("Richard", "Sales", 10000);
  Employee* sales_executive2 = new Employee("Rob", "Sales", 10000);

  CEO->add(head_sales);
  CEO->add(head_marketing);
  head_sales->add(sales_executive1);
  head_sales->add(sales_executive2);
  head_marketing->add(clerk1);
  head_marketing->add(clerk2);

  std::cout << CEO->to_str() << std::endl;
  for (Employee* head_employee : CEO->get_subordinates()) {
    std::cout << head_employee->to_str() << std::endl;
    for (Employee* employee : head_employee->get_subordinates()) {
      std::cout << employee->to_str() << std::endl;
    }
  }

  delete CEO;
  delete head_sales;
  delete head_marketing;
  delete clerk1;
  delete clerk2;
  delete sales_executive1;
  delete sales_executive2;

  return 0;
}

