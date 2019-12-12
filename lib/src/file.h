/* =============================================================================
> File Name: file.h
> Author: DaiDai
> Mail: daidai4269@aliyun.com
> Created Time: Mon 09 Dec 2019 11:46:24 AM CST
============================================================================= */


#include <stdio.h>

#include <string>


namespace file {


exists();
isdir();
modify_time();
size();


mkdir();
remove();


class File {
 public:

  File();

  open(std::string, std::string);
  write(std::string);
  writeline();
  close();

  flush();




};


}
