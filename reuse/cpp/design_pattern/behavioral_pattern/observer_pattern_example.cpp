// TODO: memory leak

#include <iostream>
#include <set>
#include <bitset>


// observer class
class Subject;
class Observer {
 public:
  virtual void update() = 0; // pure virtual function

 protected:
  Subject* subject;
};

// subject class
class Subject {
 public:
  int get_state() {
    return this->state;
  }

  void set_state(int state) {
    this->state = state;
    this->notify_all_observers();
  }

  void attach(Observer* observer) {
    this->observers.insert(observer);
  }

  void detach(Observer* observer) {
    this->observers.erase(observer);
  }

  void notify_all_observers() {
    for (Observer* observer : this->observers) {
      observer->update();
    }
  }

 private:
  std::set<Observer* > observers;
  int state; // msg
};


// create observer entity class
class BinaryObserver: public Observer {
 public:
  BinaryObserver(Subject* subject) {
    this->subject = subject;
    this->subject->attach(this);
  }

  ~BinaryObserver() {
    this->subject->detach(this);
  }

  virtual void update() {
    std::cout << "BinaryObserver::update() " << std::bitset<sizeof(int) * 8>(this->subject->get_state()) << std::endl;
  }
};

class OctalObserver: public Observer {
 public:
  OctalObserver(Subject* subject) {
    this->subject = subject;
    this->subject->attach(this);
  }

  ~OctalObserver() {
    this->subject->detach(this);
  }

  virtual void update() {
    std::cout << "OctalObserver::update() " << std::oct << this->subject->get_state() << std::endl;
  }
};

class HexaObserver: public Observer {
 public:
  HexaObserver(Subject* subject) {
    this->subject = subject;
    this->subject->attach(this);
  }

  ~HexaObserver() {
    this->subject->detach(this);
  }

  virtual void update() {
    std::cout << "HexaObserver::update() " << std::hex << this->subject->get_state() << std::endl;
  }
};

// using observer pattern example
int main() {
  Subject* subject = new Subject();

  BinaryObserver bo(subject);
  OctalObserver  oo(subject);
  HexaObserver   ho(subject);

  std::cout << "First state change: 15" << std::endl;
  subject->set_state(15);
  std::cout << "Second state change: 10" << std::endl;
  subject->set_state(10);

  delete subject;

  return 0;
}
