/* =============================================================================
> File Name: random.h
> Author: DaiDai
> Mail: daidai4269@aliyun.com
> Created Time: Mon 09 Dec 2019 11:03:45 AM CST
============================================================================= */


#ifndef DAIDAI_RANDOM_H_
#define DAIDAI_RANDOM_H_


// TODO
#include <stdlib.h>


// C Standard library
double random(double from, double to);


class Random {
 public:
  //
  Random();
  Random(float from, float to)


  // generate next random number
  double next();


  //
  template <typename Type>
  Type choice();


};



#endif // DAIDAI_RANDOM_H_



