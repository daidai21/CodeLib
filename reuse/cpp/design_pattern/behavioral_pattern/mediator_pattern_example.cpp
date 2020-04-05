#include <iostream>
#include <string>
#include <chrono>
#include <ctime>


class User;
struct ChatRoom {
 public:
  void show_message(User* user, std::string message);
} chat_room;


class User {
 public:
  User(std::string name) : name(name) { }

  std::string get_name() {
    return this->name;
  }

  void set_name(std::string name) {
    this->name = name;
  }

  void send_message(std::string message) {
    chat_room.show_message(this, message);
  }

 private:
  std::string name;
};

void ChatRoom::show_message(User* user, std::string message) {
  using std::chrono::system_clock;
  std::time_t curr_time = system_clock::to_time_t(system_clock::now());
  std::cout << std::ctime(&curr_time) << " [" << user->get_name() << "] : "
            << message << std::endl;
}

int main() {
  User* robert = new User("Robert");
  User* john   = new User("John");

  robert->send_message("Hi! John!");
  john->send_message("Hello! Robert");

  delete robert;
  delete john;

  return 0;
}

