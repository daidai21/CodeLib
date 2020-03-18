// light log

#ifndef __LOG__HPP__
#define __LOG__HPP__


#include <iostream>


namespace log {


enum LOG_LEVEL {
  LOG_LEVEL_INFO;
  LOG_LEVEL_WARNING;
  LOG_LEVL_ERROR;
};

#define COLOR_ERRO
#define COLOR_INFO
#define COLOR_WARN
#define COLOR_FILE
#define COLOR_LINE
#define COLOR_FUNC
#define DELIMITER " "

// TODO
// https://github.com/Shenggan/SnowFlake/blob/master/utils/lightlog.h

} // namespace log


#endif // __LOG__HPP__

