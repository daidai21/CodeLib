#include <iostream>
#include <string>
#include <vector>


class Memento {
 public:
  Memento(std::string state) : state(state) { }

  std::string get_state() {
    return this->state;
  }

 private:
  std::string state;
};


class Originator {
 public:
  void set_state(std::string state) {
    this->state = state;
  }

  std::string get_state() {
    return this->state;
  }

  Memento* save_state_to_memento() {
    return new Memento(this->state);
  }

  void get_state_from_memento(Memento* memento) {
    this->state = memento->get_state();
  }

 private:
  std::string state;
};


class CareTaker {
 public:
  void add(Memento* state) {
    this->memento_list.push_back(state);
  }

  Memento* get(int idx) {
    return this->memento_list.at(idx);
  }

 private:
  std::vector<Memento* > memento_list;
};


int main() {
  Originator* originator = new Originator();
  CareTaker*  care_taker = new CareTaker();

  originator->set_state("State #1");
  originator->set_state("State #2");
  care_taker->add(originator->save_state_to_memento());
  originator->set_state("State #3");
  care_taker->add(originator->save_state_to_memento());
  originator->set_state("State # 4");

  std::cout << "Current State: " << originator->get_state() << std::endl;
  originator->get_state_from_memento(care_taker->get(0));
  std::cout << "First saved State: " << originator->get_state() << std::endl;
  originator->get_state_from_memento(care_taker->get(1));
  std::cout << "Second saved State: " << originator->get_state() << std::endl;

  delete originator;
  delete care_taker;

  return 0;
}

