#ifndef __LOG__HPP__
#define __LOG__HPP__


#include <iostream>
#include <ostream>
#include <fstream>
#include <sstream>
#include <string>
#include <memory>
#include <mutex>
#include <cstdlib>

namespace log {


enum LOG_LEVEL {
  LOG_LEVEL_INFO,
  LOG_LEVEL_WARNING,
  LOG_LEVEL_ERROR
};

#define COLOR_ERRO 31
#define COLOR_INFO 37
#define COLOR_WARN 33
#define COLOR_FILE 35
#define COLOR_LINE 32
#define COLOR_FUNC 36
#define DELIMITER  " "

class Message {
 public:
  Message(const int level = 0,
          std::string file = NULL,
          std::string function = NULL,
          const int line_number = 0) {
    this->head_color = this->log_header(level, file, function, line_number, true);
    this->head       = this->log_header(level, file, function, line_number, false);
  }

  template <typename T>
  Message& operator<<(const T & t) {
    std::stringstream ss;
    ss << t;
    this->msg += ss.str();
    return *this;
  }

  std::string get_string(bool use_color = true) const {
    if (use_color) {
      return this->head_color + this->msg;
    } else {
      return this->head + this->msg;
    }
  }

 private:
  std::string color_str(int color,
                        int bold,
                        const std::string& delimiter,
                        const std::string& t,
                        bool use_color = true) {
    std::stringstream ss;
    if (use_color) {
      ss << "\033[" << bold << ";" << color << "m";
    }
    ss << t;
    if (use_color) {
      ss << "\033[0m";
    }
    ss << delimiter;
    return ss.str();
  }

  std::string log_header(int level,
                         std::string file,
                         std::string function,
                         int line_numuber,
                         bool use_color = true) {
    std::stringstream ss;
    std::stringstream st;

    int color = 39;
    if (level == 2) {
      color = COLOR_ERRO;
      st << "[ERRO]";
    } else if (level == 0) {
      color = COLOR_INFO;
      st << "[INFO]";
    } else if (level == 1) {
      color = COLOR_WARN;
      st << "[WARN]";
    }
    ss << this->color_str(color, 1, DELIMITER, st.str(), use_color);

    std::time_t raw_time;
    struct tm* time_info;
    char time_buf[30];
    std::time(&raw_time);
    time_info = std::localtime(&raw_time);
    std::strftime(time_buf, 30, "%Y/%m/%d-%H:%M:%S", time_info);
    ss << this->color_str(color, 0, DELIMITER, time_buf, use_color);

    int p_pos = 0;
    for (int i = file.length() - 1; i > 0; --i) {
      if (file.substr(i, 1) == std::string("/")) {
        p_pos = i + 1;
        break;
      }
    }
    file = file.substr(p_pos, file.length() - p_pos);
    ss << this->color_str(COLOR_FILE, 0, ":",       file,                         use_color); // 35
    ss << this->color_str(COLOR_LINE, 1, ":",       std::to_string(line_numuber), use_color); // 32
    ss << this->color_str(COLOR_FUNC, 0, DELIMITER, function,                     use_color); // 36
    return ss.str();
  }

 private:
  std::string head;
  std::string head_color;
  std::string msg;
};


// Singleton Class
class Logger {
 public:
  static Logger* get_instance() {
    if (instance == nullptr) {
      mtx.lock();
      if (instance == nullptr) {
        instance.reset(new Logger);
      }
      mtx.unlock();
    }
    return instance.get();
  }

  void init_log_file() {}

  void set_level(int level) { this->level = LOG_LEVEL(level); }
  int get_level() { return this->level; }

  void set_console(bool console) { this->console = console; }
  int get_console() { return this->console; }

  void operator+=(const Message& msg) {
    this->mtx.lock();
    if (this->console) {
      std::cout << msg.get_string() + '\n';
    }
    if (this->file) {
      this->log_file << msg.get_string(false) + '\n';
    }
    this->mtx.unlock();
  }

 private:
  static std::unique_ptr<Logger> instance;
  LOG_LEVEL                      level;
  static std::mutex              mtx;
  bool                           console;
  bool                           file;
  std::ofstream                  log_file;

 private:
  Logger() {
    if (std::getenv("LOG_LVL") == NULL) {
      this->level = LOG_LEVEL_INFO;
    } else {
      std::string env_level = std::getenv("LOG_LVL");
      if (env_level == "WARN") {
        this->level = LOG_LEVEL_WARNING;
      } else if (env_level == "ERRO") {
        this->level = LOG_LEVEL_ERROR;
      } else {
        this->level = LOG_LEVEL_INFO;
      }
    }
    this->console = true;
    this->file = false;
  }
};

std::unique_ptr<Logger> Logger::instance = nullptr;
std::mutex              Logger::mtx;

#define LOG(level) \
  if (level >= (*log::Logger::get_instance()).get_level()) \
    (*log::Logger::get_instance()) += log::Message(level, __FILE__, __FUNCTION__, __LINE__)

#define INFO 0
#define WARN 1
#define ERRO 2

#define LOG_INFO LOG(INFO)
#define LOG_WARN LOG(WARN)
#define LOG_ERRO LOG(ERRO)

#define LOG_LVL(level) (*log::Logger::get_instance()).set_level(level)

#define LOG_LVL_INFO LOG_LVL(INFO)
#define LOG_LVL_WARN LOG_LVL(WARN)
#define LOG_LVL_ERRO LOG_LVL(ERRO)

#define LOG_CONSOLE_OFF (*log::Logger::get_instance()).set_console(false)
#define LOG_CONSOLE_ON  (*log::Logger::get_instance()).set_console(true)

} // namespace log


#endif // __LOG__HPP__
