/* =============================================================================
> File Name: atomic.h
> Author: DaiDai
> Mail: daidai4269@aliyun.com
> Created Time: Mon 09 Dec 2019 10:56:20 AM CST
============================================================================= */


#ifndef DAIDAI_ATOMIC_H_
#define DAIDAI_ATOMIC_H_


#ifdef _WIN32
#include "win/atomic.h"
#else
#include "unix/atomic.h"
#endif


#endif // DAIDAI_ATOMIC_H_

