#include <iostream>
#include <string>


class State;
class Context {
 public:
  void set_state(State* state) {
    this->state = state;
  }

  State* get_state() {
    return this->state;
  }

 private:
  State* state;
};

// interface
class State {
 public:
  virtual void do_action(Context* context) = 0;

  virtual std::string to_str() = 0;
};

class StartState: public State {
 public:
  virtual void do_action(Context* context) {
    std::cout << "Player is in start state" << std::endl;
    context->set_state(this);
  }

  virtual std::string to_str() {
    return "Start State";
  }
};

class StopState: public State {
 public:
  virtual void do_action(Context* context) {
    std::cout << "Player is in stop state" << std::endl;
    context->set_state(this);
  }

  virtual std::string to_str() {
    return "Stop State";
  }
};


int main() {
  Context* context = new Context();

  StartState* start_state = new StartState();
  start_state->do_action(context);

  std::cout << context->get_state()->to_str() << std::endl;

  StopState* stop_state = new StopState();
  stop_state->do_action(context);

  std::cout << context->get_state()->to_str() << std::endl;

  delete context;
  delete start_state;
  delete stop_state;

  return 0;
}

