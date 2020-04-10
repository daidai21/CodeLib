#include <iostream>
#include <string>


// abstract class
class AbstractLogger {
 public:
  ~AbstractLogger() {
    AbstractLogger* cur_ptr = this->next_logger;
    while (cur_ptr != nullptr) {
      cur_ptr = cur_ptr->next_logger;
      delete this->next_logger;
      this->next_logger = cur_ptr;
    }
  }

  void set_next_logger(AbstractLogger* next_logger) {
    this->next_logger = next_logger;
  }

  void log_message(int level, std::string message) {
    if (this->level <= level) {
      this->write(message);
    }
    if (next_logger != NULL) {
      this->next_logger->log_message(level, message);
    }
  }

 protected:
  AbstractLogger* next_logger;
  int level;

  virtual void write(std::string message) = 0;
 public:
  static int INFO;
  static int DEBUG;
  static int ERROR;
};

int AbstractLogger::INFO  = 1;
int AbstractLogger::DEBUG = 2;
int AbstractLogger::ERROR = 3;


// entity class
class ConsoleLogger: public AbstractLogger {
 public:
  ConsoleLogger(int level) {
    this->level = level;
  }

 protected:
  virtual void write(std::string message) {
    std::cout << "Standard Console::Logger: " << message << std::endl;
  }
};

class ErrorLogger: public AbstractLogger {
 public:
  ErrorLogger(int level) {
    this->level = level;
  }

 protected:
  virtual void write(std::string message) {
    std::cout << "Error Console::Logger: " << message << std::endl;
  }
};

class FileLogger: public AbstractLogger {
 public:
  FileLogger(int level) {
    this->level = level;
  }

 protected:
  virtual void write(std::string message) {
    std::cout << "File::Logger: " << message << std::endl;
  }
};


static AbstractLogger* get_chain_of_loggers() {
  AbstractLogger* error_logger   = new ErrorLogger(AbstractLogger::ERROR);
  AbstractLogger* file_logger    = new FileLogger(AbstractLogger::DEBUG);
  AbstractLogger* concole_logger = new ConsoleLogger(AbstractLogger::INFO);

  error_logger->set_next_logger(file_logger);
  file_logger->set_next_logger(concole_logger);

  return error_logger;
}


int main() {
  AbstractLogger* logger_chain = get_chain_of_loggers();

  logger_chain->log_message(AbstractLogger::INFO, "This is an information.");
  std::cout << std::endl;
  logger_chain->log_message(AbstractLogger::DEBUG,
      "This is a debug level information.");
  std::cout << std::endl;
  logger_chain->log_message(AbstractLogger::ERROR,
      "This is an error information.");
  std::cout << std::endl;

  delete logger_chain;

  return 0;
}

