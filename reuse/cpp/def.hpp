// Version C++11

#include <string>
#include <algorithm>
#include <cctype>


typedef unsigned long long int ulli_t;
typedef unsigned long int      uli_t;
typedef unsigned int           ui_t;
typedef long long int          lli_t;
typedef long int               li_t;


#define ERR_EXIT(m) \
  do{ \
    perror(m); \
    exit(EXIT_FAILURE); \
  } while(0)


typedef unsigned char byte;


#define CAS atomic_compare_exchange_weak


inline std::string to_upper(std::string str) {
  std::string res = str;
  std::transform(res.begin(), res.end(), res.begin(), std::toupper);
}

inline std::string to_lower(std::string str) {
  std::string res = str;
  std::transform(res.begin(), res.end(), res.begin(), std::tolower);
}


inline bool equals_ignore_case(std::string str1, std::string str2) {
  return to_upper(str1) == to_upper(str2);
}
