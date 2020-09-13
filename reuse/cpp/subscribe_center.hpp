/* ****************************************************************************
 * File Name   : subscribe_center.hpp
 * Author      : DaiDai
 * Mail        : daidai4269@aliyun.com
 * Created Time: 日  9/13 14:20:23 2020
 *************************************************************************** */


#include <vector>
#include <string>
#include <unordered_map>
#include <shared_mutex>


// https://github.com/chxuan/cpp-utils/blob/master/subscribe_center/subscribe_center.h
// TODO


class SubscribeCenter {
 public:
  void add_msg(const std::string& msg_name, const std::string& session_id) {
    std::shared_lock<std::shared_mutex> lock(this->mtx);
    // TODO
  }

  std::vector<std::string> get_session_id(const std::string& msg_name) {
    // TODO
  }

  void mv_msg(const std::string& session_id) {
    // TODO
  }

  void clear() {
    std::shared_lock<std::shared_mutex> lock(this->mtx);
    this->msg2session.clear();
  }

 private:
  std::unordered_multimap<std::string, std::string> msg2session;
  std::shared_mutex mtx;
};
