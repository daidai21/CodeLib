/* ****************************************************************************
 * File Name   : reactor_used_select.cpp
 * Author      : DaiDai
 * Mail        : daidai4269@aliyun.com
 * Created Time: 二  6/23 20:30:32 2020
 *************************************************************************** */


#include <iostream>
#include <algorithm>    // For max_element
#include <thread>       // For std::thread
#include <functional>

#include <sys/select.h> // For fd_set, FD_SET, FD_ISSET, FD_ZERO
#include <sys/types.h>  // For addrinfo, getaddrinfo
#include <sys/socket.h> // For addrinfo, getaddrinfo
#include <netdb.h>      // For addrinfo, getaddrinfo
#include <unistd.h>     // For close

#include "./reactor_used_select.hpp"


// Reactor
namespace reactor {

void EventHandler::operator()(int fd, EventType event_type) {
  this->handle(fd, event_type);
}

using EventHandlerPtr = std::shared_ptr<EventHandler>;

void ReactorInterface::operator()() {
  while(true) {
    this->run();
  }
}

void ReactorInterface::register_event_handler(int fd,
                                              const EventHandlerPtr& handler) {
  auto search = this->_events.find(fd);
  if (search == this->_events.end()) {
    std::list<EventHandlerPtr> handler_list{handler};
    this->_events[fd] = handler_list;
  } else {
    search->second.push_back(handler);
  }
}

void ReactorInterface::get_event_handler_for(
    int fd,
    std::list<EventHandlerPtr>& handlers) const {
  auto search = this->_events.find(fd);
  if (search != this->_events.end()) {
    std::copy(search->second.cbegin(),
              search->second.cend(),
              std::back_inserter(handlers));
  }
}

ReactorSelectImpl::~ReactorSelectImpl() {}; // TODO

void ReactorSelectImpl::run() {
  std::vector<int> read_fds;
  std::vector<int> write_fds;
  std::vector<int> except_fds;

  int result = sys::select(read_fds, write_fds, except_fds);

  switch (result) {
    case -1:
      std::cout << "Error in select" << std::endl;
      break;
    case 0:
      std::cout << "Timeout in select" << std::endl;
      break;
    default:
      {
        for (auto fd : read_fds)
          std::cout << "Ready to READ: " << fd << std::endl;
        for (auto fd : write_fds)
          std::cout << "Ready to WRITE: " << fd << std::endl;
        break;
      }
  }

}

}; // namespace reactor


// System
namespace sys {

void fd_set_func(int fd, fd_set& fds) {
  FD_SET(fd, &fds);
}

bool fd_is_set_func(int fd, const fd_set& fds) {
  return FD_ISSET(fd, &fds) == 1;
}

int select(std::vector<int>& io_read_fds,
           std::vector<int>& io_write_fds,
           std::vector<int>& io_except_fds,
           int timeout_seconds) {
  fd_set read_fds;
  fd_set write_fds;
  fd_set except_fds;

  FD_ZERO(&read_fds);
  FD_ZERO(&write_fds);
  FD_ZERO(&except_fds);

  std::for_each(io_read_fds.begin(),
                io_read_fds.end(),
                std::bind(fd_set_func, std::placeholders::_1, read_fds));
  std::for_each(io_write_fds.begin(),
                io_write_fds.end(),
                std::bind(fd_set_func, std::placeholders::_1, write_fds));
  std::for_each(io_except_fds.begin(),
                io_except_fds.end(),
                std::bind(fd_set_func, std::placeholders::_1, except_fds));

  // find the max in the three file descriptons sets
  int max_read_fd = 0;
  if (!io_read_fds.empty()) {
    max_read_fd = *std::max_element(io_read_fds.begin(), io_read_fds.end());
  }
  int max_write_fd = 0;
  if (!io_write_fds.empty()) {
    max_write_fd = *std::max_element(io_write_fds.begin(), io_write_fds.end());
  }
  int max_except_fd = 0;
  if (!io_except_fds.empty()) {
    max_except_fd = *std::max_element(io_except_fds.begin(), io_except_fds.end());
  }

  int max_fd = std::max(max_read_fd, std::max(max_write_fd, max_except_fd));

  // timeout conversion
  timeval timeout;
  timeout.tv_sec  = timeout_seconds;
  timeout.tv_usec = 0;

  // the system call to 'select()'
  int result = select(max_fd, &read_fds, &write_fds, &except_fds, &timeout);

  // filter the ready for I/O fds
  io_read_fds.erase(std::remove_if(io_read_fds.begin(), io_read_fds.end(),
                                   std::bind(fd_is_set_func,
                                             std::placeholders::_1,
                                             read_fds)),
                    io_read_fds.end());
  io_write_fds.erase(std::remove_if(io_write_fds.begin(), io_write_fds.end(),
                                    std::bind(fd_is_set_func,
                                              std::placeholders::_1,
                                              write_fds)),
                     io_write_fds.end());
  io_except_fds.erase(std::remove_if(io_except_fds.begin(), io_except_fds.end(),
                                     std::bind(fd_is_set_func,
                                               std::placeholders::_1,
                                               except_fds)),
                      io_except_fds.end());

  return result;
}

}; // namespace sys


// Threads
namespace threads {

void ConnectionAcceptor::operator()() {
  struct addrinfo hints;
  hints.ai_canonname = NULL;
  hints.ai_addr      = NULL;
  hints.ai_next      = NULL;
  hints.ai_socktype  = SOCK_STREAM;
  hints.ai_family    = AF_UNSPEC;
  hints.ai_flags     = AI_PASSIVE;

  struct addrinfo* result;
  struct addrinfo* rp;
  if (getaddrinfo(NULL, _port.c_str(), &hints, &result) != 0) {
    std::cout << "Error getting address info" << std::endl;
    return ;
  }
  int sfd = 0;
  int opt_val = 1;
  for (rp = result; rp != NULL; rp = rp->ai_next) {
    sfd = socket(rp->ai_family, rp->ai_socktype, rp->ai_protocol);
    if (sfd == -1) {
      continue;
    }
    if (setsockopt(sfd, SOL_SOCKET, SO_REUSEADDR, &opt_val,
                   sizeof(opt_val)) == -1 ) {
      std::cout << "Error setting SO_REUSEADDR option" << std::endl;
    }
    if (bind(sfd, rp->ai_addr, rp->ai_addrlen) == 0) {
      std::cout << "Socket " << sfd << " bound to " << rp->ai_addr << std::endl;
      break; // SUCCESS
    }
    close(sfd);
    std::cout << "Error when binding the socket." << std::endl;
    return ;
  }
  if (listen(sfd, 5) == -1) {
    std::cout << "Error when listening" << std::endl;
    return ;
  }
  freeaddrinfo(result);
  while (true) {
    int cfd = accept(sfd, NULL, NULL);
    if (cfd == -1) {
      std::cout << "Accept() failed" << std::endl;
    } else {
      std::cout << "Connection created" << std::endl;
      this->_traffic_manager->register_event_handler(cfd, nullptr);
    }
  }
}

}; // namespace threads


// Main 
int main(int argc, char* argv[]) {
  using namespace threads;

  auto tracffic_manager = std::make_shared<reactor::ReactorSelectImpl>(); // BUG: https://stackoverflow.com/questions/23012621/pure-virtual-and-stdshared-ptr
  ConnectionAcceptor connection_acceptor{"localhost", "4747",
                                                  tracffic_manager};

  std::thread acceptor_thread(connection_acceptor);
  std::thread tracffic_manager_thread(*tracffic_manager);
  acceptor_thread.join();
  tracffic_manager_thread.join();

  return 0;
}
