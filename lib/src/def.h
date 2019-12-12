/* =============================================================================
> File Name: def.h
> Author: DaiDai
> Mail: daidai4269@aliyun.com
> Created Time: Sun 08 Dec 2019 09:54:05 PM CST
============================================================================= */


#ifndef DAIDAI_DEF_H_
#define DAIDAI_DEF_H_


#include <stdint.h>


typedef int8_t int8;
typedef int16_t int16;
typedef int32_t int32;
typedef int64_t int64;

typedef uint8_t uint8;
typedef uint16_t uint16;
typedef uint32_t uint32;
typedef uint64_t uint64;


// TODO: variable type scope


template<typename TypeTo, typename TypeFrom>
inline TypeTo force_case(TypeFrom var) {
  return (TypeTo) var;
}


#endif // DAIDAI_DEF_H_

