#include "./log.hpp"

#include <iostream>

using namespace std;
using namespace log;

int main() {
  LOG_CONSOLE_ON;

  LOG(INFO) << "test INFO";
  LOG(ERRO) << "test ERRO";
  LOG(WARN) << "test WARN";
  cout << endl;

  LOG_INFO << "test LOG_INFO";
  LOG_ERRO << "test LOG_ERRO";
  LOG_WARN << "test LOG_WARN";

  LOG_CONSOLE_OFF;

  LOG(INFO) << "test INFO";
  LOG(ERRO) << "test ERRO";
  LOG(WARN) << "test WARN";

  cout << endl;

  LOG_CONSOLE_ON;
  LOG_FILE("./log_test.temp.log");
  LOG(INFO) << "test INFO";
  LOG(ERRO) << "test ERRO";
  LOG(WARN) << "test WARN";

  cout << endl;

  LOG_LVL_INFO;
  LOG_COUT << "123";
  LOG_LVL_WARN;
  LOG_COUT << "123";
  LOG_LVL_ERRO;
  LOG_COUT << "123";

  return 0;
}
