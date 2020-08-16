#include "./log.hpp"


using namespace log;


int main() {
  LOG_CONSOLE_ON;
  LOG(INFO) << "test INFO";
  LOG(ERRO) << "test ERRO";
  LOG(WARN) << "test WARN";

  return 0;
}
