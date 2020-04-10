#include <iostream>
#include <string>
#include <vector>
#include <algorithms>

// TODO: BUG

class Person {
 public:
  Person(std::string name, std::string gender, std::string marital_status) :
      name(name), gender(gender), marital_status(marital_status){ }

  std::string get_name() {
    return this->name;
  }

  std::string get_gender() {
    return this->gender;
  }

  std::string get_marital_status() {
    return this->marital_status;
  }

 private:
  std::string name;
  std::string gender;
  std::string marital_status;
};

class Criteria {
 public:
  virtual std::vector<Person*> meet_criteria(std::vector<Person*> persons) = 0;
};


class CriteriaMale : public Criteria {
 public:
  virtual std::vector<Person*> meet_criteria(std::vector<Person*> persons) {
    for (Person* person : persons) {
      // if (person->gender() == std::to_string("MALE")) {
      if (person->gender() == std::string("MALE")) {
      // if (person->gender().compare("MALE")) {
        this->persons.push_back(person);
      }
    }
  }
};


class CriteriaFemale : public Criteria {
 public:
  virtual std::vector<Person*> meet_criteria(std::vector<Person*> persons) {
    for (Person* person : persons) {
      if (person->gender() == "FEMALE") {
        this->persons.push_back(person);
      }
    }
  }
};

class CriteriaSingle : public Criteria {
 public:
  virtual std::vector<Person*> meet_criteria(std::vector<Person*> persons) {
    for (Person* person : persons) {
      if (person->gender() == "SINGLE") {
        this->persons.push_back(person);
      }
    }
  }
};

class AndCriteria : public Criteria {
 public:
  AndCriteria(Criteria* criteria, Criteria* other_criteria) :
      criteria(criteria), other_criteria(other_criteria) { }

  virtual std::vector<Person*> meet_criteria(std::vector<Person*> persons) {
    std::vector<Person*> first_criteria_persons = criteria->meet_criteria(
        person);
    return this->other_criteria->meet_criteria(first_criteria_persons);
  }

 private:
  Criteria* criteria;
  Criteria* other_criteria;
};

class OrCriteria : public Criteria {
 public:
  virtual OrCriteria(Criteria* criteria, Criteria* other_criteria):
      criteria(criteria), other_criteria(other_criteria) { }

  virtual std::vector<Person*> meet_criteria(std::vector<Person*> persons) {
    std::vector<Person*> first_criterial_items = this->criteria->meet_criteria(
        persons);
    std::vector<Person*> other_criterial_items =
        this->other_criteria->meet_criteria(persons);

    for (Person* person : other_criterial_items) {
      if (std::find(first_criterial_items.begin(), first_criterial_items.end(),
          person) != first_criterial_items.end()) {
        first_criterial_items.push_back(person);
      }
    }
    return first_criterial_items;
  }

 private:
  Criteria* criteria;
  Criteria* other_criteria;
};


static void print_persons(std::vector<Person*> persons) {
  for (Person* person : persons) {
    std::cout << "Person : [ Name : "  << person->get_name()
              << ", Gender : "         << person->get_gender()
              << ", Marital Status : " << person->get_marital_status()
              << " ]" << std::endl;
  }
}

int main() {
  std::vector<Person*> persons;

  persons.push_back(new Person("Robert", "Male",   "Single"));
  persons.push_back(new Person("John",   "Male",   "Married"));
  persons.push_back(new Person("Laura",  "Female", "Married"));
  persons.push_back(new Person("Diana",  "Female", "Single"));
  persons.push_back(new Person("Mike",   "Male",   "Single"));
  persons.push_back(new Person("Bobby",  "Male",   "Single"));

  Criteria* male             = new CriteriaMale();
  Criteria* female           = new CriteriaFemale();
  Criteria* single           = new CriteriaSingle();
  Criteria* single_and_male  = new AndCriteria(single, male);
  Criteria* single_or_female = new OrCriteria(single, female);

  std::cout << "\n" << "Males: " << std::endl;
  print_persons(male->meet_criteria(persons));
  std::cout << "\n" << "Females: " << std::endl;
  print_persons(female->meet_criteria(persons));
  std::cout << "\n" << "Single Males: " << std::endl;
  print_persons(single_and_male->meet_criteria(persons));
  std::cout << "\n" << "Single Or Females: " << std::endl;
  print_persons(single_or_female->meet_criteria(persons));


  delete male;
  delete female;
  delete single;
  delete single_and_male;
  delete single_or_female;

  return 0;
}

