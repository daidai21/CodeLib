// TODO: memory leak

#include <iostream>


// template class
class Game {
 public:
  virtual void initialize() = 0;
  virtual void start_play() = 0;
  virtual void end_play()   = 0;

  // template
  void play() {
    this->initialize();
    this->start_play();
    this->end_play();
  }
};


class Cricket: public Game {
 public:
  virtual void initialize() {
    std::cout << "Cricket::initialize()" << std::endl;
  }

  virtual void start_play() {
    std::cout << "Cricket::start_play()" << std::endl;
  }

  virtual void end_play() {
    std::cout << "Cricket::end_play()" << std::endl;
  }
};

class Football: public Game {
 public:
  virtual void initialize() {
    std::cout << "Football::initialize()" << std::endl;
  }

  virtual void start_play() {
    std::cout << "Football::start_play()" << std::endl;
  }

  virtual void end_play() {
    std::cout << "Football::end_play()" << std::endl;
  }
};


// using template pattern example
int main () {
  Game* game = new Cricket();
  game->play();

  std::cout << std::endl;

  game = new Football();
  game->play();

  delete game;

  return 0;
}
