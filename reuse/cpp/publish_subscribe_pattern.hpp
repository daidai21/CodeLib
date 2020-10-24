/* ****************************************************************************
 * File Name   : publish_subscribe_pattern.hpp
 * Author      : DaiDai
 * Mail        : daidai4269@aliyun.com
 * Created Time: 一 10/19 17:59:01 2020
 *************************************************************************** */


#include <iostream>

class Client {
 public:

 private:

}; // TODO

class Server {
 public:

  void publish();

  void subscribe();

 private:
  std::vector<Client> clients; //
  std::vector<Server> servers; // 
};

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}

