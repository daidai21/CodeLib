// support thread safe
// not support thread safe


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

