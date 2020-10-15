#include <stdint.h>

// TODO: not test, not over


#define bool  unsigned int
#define false 0
#define true  1
#define byte  unsigned char;

typedef int8_t  int8;
typedef int16_t int16;
typedef int32_t int32;
typedef int64_t int64;

typedef uint8_t  uint8;
typedef uint16_t uint16;
typedef uint32_t uint32;
typedef uint64_t uint64;

#define max(a, b) ((a) > (b)) ? (a) : (b)
#define min(a, b) ((a) < (b)) ? (a) : (b)



#define CAS(val, old_val, new_val) __sync_bool_compare_and_swap((val), (old_val), (new_val))


extern void bind_core(int64_t core_id);

double random_decimal(const double lower_bound, const double upper_bound) {}
float random_decimal(const float lower_bound, const float upper_bound) {}

/* convert int to char* */
char* itoa(int val, int base) {
  char* res;

  // TODO
  return res;
}


#define PI 3.14159265
