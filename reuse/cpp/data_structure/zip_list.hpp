/* ****************************************************************************
 * File Name   : zip_list.hpp
 * Author      : DaiDai
 * Mail        : daidai4269@aliyun.com
 * Created Time: 一 10/19 15:44:04 2020
 *************************************************************************** */


#include <iostream>


// http://origin.redisbook.com/compress-datastruct/ziplist.html
// TODO
class ZipList {
 public:

 private:
  bytes // ZipList length of byte
  tail // offset tail pointer
  length // length of node
  encoding // node_size: int8_t / int16_t / int32_t / int64_t
  content // vector<XXX> reference
};

// vector
