#include <iostream>
#include <string>


// interface
class Image {
 public:
  virtual void display() = 0;
};

// entity class
class RealImage: public Image {
 public:
  RealImage(std::string file_name) : file_name(file_name) {
    this->load_from_disk(file_name);
  }

  virtual void display() {
    std::cout << "Displaying " << this->file_name << std::endl;
  }

 private:
  void load_from_disk(std::string file_name) {
    std::cout << "Loading " << file_name << std::endl;
  }

 private:
  std::string file_name;
};


class ProxyImage: public Image {
 public:
  ProxyImage(std::string file_name) : file_name(file_name) { }

  ~ProxyImage() {
    delete this->real_image;
  }

  virtual void display() {
    if (this->real_image == nullptr) {
      this->real_image = new RealImage(this->file_name);
    }
    this->real_image->display();
  }

 private:
  RealImage*  real_image;
  std::string file_name;
};


// using proxy pattern example
int main() {
  Image* image = new ProxyImage("xxx.txt");

  image->display();
  std::cout << std::endl;
  image->display();

  delete image;

  return 0;
}

