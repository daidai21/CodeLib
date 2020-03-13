/* =============================================================================
> File Name: asd.hpp
> Author: DaiDai
> Mail: daidai4269@aliyun.com
> Created Time: Sat Jan 18 14:51:23 2020
============================================================================= */


// TODO:
// multiply read, single read (read add mutex when writing)
// multiply read, single read (writing to new space, then change file pointer)


template <typename DataType>
class Var {
 public:
  void Var (DataType data) {
    p = new DataType();
  }

  void ~Var() {
    delete *p;
  }

  void write(DataType data) {
    DataType* temp = new DataType(data);  // write time is long
    swap(temp, p);  // atomic
    delete temp;
  }

  DataType* read() {
    return p;
  }

 private:
  DataType* p; // read
};
