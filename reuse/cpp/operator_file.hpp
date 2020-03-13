

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

