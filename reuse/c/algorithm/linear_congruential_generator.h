/**
 * Random
 */


#include <stdint.h>


/**
 * Linear congruential generator
 * 
 * https://zh.wikipedia.org/wiki/%E7%B7%9A%E6%80%A7%E5%90%8C%E9%A4%98%E6%96%B9%E6%B3%95
 */
static uint32_t LCG() {
  static uint32_t a = 1664525U;
  static uint32_t c = 1013904223U;
  static uint32_t X0 = 0;
  X0 = a * X0 + c;
  return X0;
}
