/* =============================================================================
> File Name: file.h
> Author: DaiDai
> Mail: daidai4269@aliyun.com
> Created Time: Mon 09 Dec 2019 11:46:24 AM CST
============================================================================= */


#include <stdio.h>

#include <string>


namespace file {

/*
exists();
isdir();
modify_time();
size();


mkdir();
remove();
*/

class File {
 public:
  File() = default;
  ~File() = default; // ensure file status is closed

  void open(std::string filename, std::string mode) {
    fp_ = fopen(filename.data(), mode.data());
  }

  bool write(std::string text) {
    fputs(text.data(), fp_);
  }

  bool writeline();

  bool close() {
    fclose(fp_);
  }

  bool flush();

 private:
  FILE* fp_;

};


} // namespace file

