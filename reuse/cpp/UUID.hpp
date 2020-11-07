/* ****************************************************************************
 * File Name   : UUID.hpp
 * Author      : DaiDai
 * Mail        : daidai4269@aliyun.com
 * Created Time: 六 11/ 7 17:19:53 2020
 *************************************************************************** */

#include <mutex>
#include <random>
#include <sstream>

// https://stackoverflow.com/questions/24365331/how-can-i-generate-uuid-in-c-without-using-boost-library
// https://juejin.im/post/6864199183957262350

/**
 * TODO: support thread safe
 */
class UUID {
 public:
  UUID() {
    version_ = 4;  // default version is V4
  }

  UUID(int version) {
    assert(version == 1 || version == 2 || version == 3 || version == 4 || version == 5);
    version_ = version;
  }

  std::string generate();

 private:
  std::string generate_v1();
  std::string generate_v2();
  std::string generate_v3();
  std::string generate_v4();
  std::string generate_v5();

 private:
  int version_;
  std::mutex mtx_;
};

std::string UUID::generate() {
  switch (version_) {
    case 1:
      return generate_v1();
      break;
    case 2:
      return generate_v2();
      break;
    case 3:
      return generate_v3();
      break;
    case 4:
      return generate_v4();
      break;
    case 5:
      return generate_v5();
      break;
    default:
      break;
  }
  return NULL;
}

std::string UUID::generate_v1() {
  //
}

std::string UUID::generate_v2() {
  //
}

std::string UUID::generate_v3() {
  //
}

std::string UUID::generate_v4() {
  //
}

std::string UUID::generate_v5() {
  //
}
