/* ****************************************************************************
 * File Name   : reactor_used_select.hpp
 * Author      : DaiDai
 * Mail        : daidai4269@aliyun.com
 * Created Time: 二  6/23 20:30:35 2020
 *************************************************************************** */


#ifndef __MAIN_HPP__
#define __MAIN_HPP__


#include <memory>
#include <list> // TODO: exchange to forward_list
#include <map>  // TODO: exchange to unordered_map
#include <vector>
#include <string>


// Reactor
namespace reactor {

enum class EventType {
  READ,
  WRITE
};

class EventHandler {
 public:
  void operator()(int fd, EventType event_type);

 protected:
  virtual void handle(int fd, EventType event_type) = 0;
};

using EventHandlerPtr = std::shared_ptr<EventHandler>;

class ReactorInterface {
 public:
  void operator()();
  void register_event_handler(int fd,
                              const EventHandlerPtr& handler);
  void get_event_handler_for(int fd,
                             std::list<EventHandlerPtr>& handlers) const;

 protected:
  virtual void run() = 0;

 private:
  std::map<int, std::list<EventHandlerPtr>> _events;
};

class ReactorSelectImpl: public ReactorInterface {
 public:
  virtual ~ReactorSelectImpl() = 0; // TODO

 protected:
  virtual void run() override;
};

}; // namespace reactor


// System
namespace sys {

int select(std::vector<int>& io_read_fds,
           std::vector<int>& io_write_fds,
           std::vector<int>& io_except_fds,
           int timeout_seconds = 0);

}; // namespace sys


// Threads
namespace threads {

class ConnectionAcceptor {
 public:
  ConnectionAcceptor(const std::string& address,
                     const std::string& port,
                     const std::shared_ptr<reactor::ReactorInterface>& traffic_manager)
    : _address(address),
     _port(port),
     _traffic_manager(traffic_manager) {};
  void operator()();

 private:
  std::string _address;
  std::string _port;
  std::shared_ptr<reactor::ReactorInterface> _traffic_manager;
};

}; // namespace threads


#endif // __MAIN_HPP__
