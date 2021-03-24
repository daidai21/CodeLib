// TODO
// https://redisbook.readthedocs.io/en/latest/internal-datastruct/sds.html
// https://github.com/huangz1990/redis-3.0-annotated/blob/unstable/src/sds.h


#ifndef __STR_H__
#define __STR_H__


/**
 * Type rename
 */
typedef char* str;

/**
 * str container
 */
struct str_con {
  /* buf size */
  int len;

  /* free size */
  int free;

  /* data space */
  char buf[];
};




#endif // __STR_H__
