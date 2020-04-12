// support thread safe
// C++11
class Singleton {
 private:
  Singleton() {}
  ~Singleton() {}

 public:
  Singleton(Singleton const&) = delete;
  Singleton& operator=(Singleton const&) = delete;

  static Singleton& get_instance() {
    static Singleton instance;
    return instance;
  }
};

