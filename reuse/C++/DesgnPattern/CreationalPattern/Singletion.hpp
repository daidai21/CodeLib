/* =============================================================================
> File Name: Singletion.hpp
> Author: DaiDai
> Mail: daidai4269@aliyun.com
> Created Time: Sun 03 Nov 2019 08:09:21 PM CST
============================================================================= */


// support thread safe


class Singletion {
 private:
  Singletion() {}
  ~Singletion() {}

 public:
  Singletion(Singletion const&) = delete;
  Singletion& operator=(Singletion const&) = delete;

  static Singletion& get_instance() {
    static Singletion instance;
    return instance;
  }
};

