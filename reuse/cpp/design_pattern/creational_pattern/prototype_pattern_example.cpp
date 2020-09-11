#include <iostream>
#include <string>
#include <map>

// TODO: BUG
// g++ open optimize error

// cloneable interface abstract class
// prototype
class Shape {
 public:
  virtual Shape* clone() {
    Shape* res;
    res->id   = this->id;
    res->type = this->type;
    return res;
  }

  std::string get_type() {
    return this->type;
  }

  std::string get_id() {
    return this->id;
  }

  void set_id(std::string id) {
    this->id = id;
  }

  virtual void draw() = 0;

 private:
  std::string id;

 protected:
  std::string type;
};

// entity class
class Rectangle: public Shape {
 public:
  Rectangle() {
    this->type = "Rectangle";
  }

  virtual void draw() {
    std::cout << "Inside Rectangle::draw() method." << std::endl;
  }
};

class Square: public Shape {
 public:
  Square() {
    this->type = "Square";
  }

  virtual void draw() {
    std::cout << "Inside Square::draw() method." << std::endl;
  }
};

class Circle: public Shape {
 public:
  Circle() {
    this->type = "Circle";
  }

  virtual void draw() {
    std::cout << "Inside Circle::draw() method." << std::endl;
  }
};

// DB class for require entity class
class ShapeCache {
 public:
  // load cache
  ShapeCache() {
    Circle* circle = new Circle();
    circle->set_id("1");
    shape_map[circle->get_id()] = circle;

    Square* square = new Square();
    square->set_id("2");
    shape_map[square->get_id()] = square;

    Rectangle* rectangle = new Rectangle();
    rectangle->set_id("3");
    shape_map[rectangle->get_id()] = rectangle;
  }

  ~ShapeCache() {
    for (auto it = shape_map.begin(); it != shape_map.end(); ++it) {
      delete it->second;
    }
  }

  Shape* get_shape(std::string shape_id) {
    return shape_map.at(shape_id)->clone();
  }

 private:
  std::map<std::string, Shape*> shape_map;
};

//
int main() {
  ShapeCache sc;

  Shape* cloned_shape0 = sc.get_shape("1");
  std::cout << "Shape: " << cloned_shape0->get_type() << std::endl;

  Shape* cloned_shape1 = sc.get_shape("2");
  std::cout << "Shape: " << cloned_shape1->get_type() << std::endl;

  Shape* cloned_shape2 = sc.get_shape("3");
  std::cout << "Shape: " << cloned_shape2->get_type() << std::endl;

  return 0;
}

