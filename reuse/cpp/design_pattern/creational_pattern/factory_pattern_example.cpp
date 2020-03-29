// TODO: memory leak

#include <iostream>
#include <string>


// interface
class Shape {
 public:
  virtual void draw() = 0; // pure virtual function
};

// entity class
class Rectangle: public Shape {
 public:
  virtual void draw() {
    std::cout << "Rectangle::draw()" << std::endl;
  }
};

class Square: public Shape {
 public:
  virtual void draw() {
    std::cout << "Square::draw()" << std::endl;
  }
};

class Circle: public Shape {
 public:
  virtual void draw() {
    std::cout << "Circle::draw()" << std::endl;
  }
};

// factory class
class ShapeFactory {
 public:
  Shape* get_shape(std::string str) {
    if (str == "Rectangle") {
      return new Rectangle();
    } else if (str == "Square") {
      return new Square();
    } else if (str == "Circle") {
      return new Circle();
    } else {
      return nullptr;
    }
  }
};


// using factory pattern example
int main() {
  ShapeFactory* shape_factory = new ShapeFactory();

  Shape* shape = shape_factory->get_shape("Rectangle");
  shape->draw();

  shape = shape_factory->get_shape("Square");
  shape->draw();

  shape = shape_factory->get_shape("Circle");
  shape->draw();

  delete shape_factory;
  delete shape;

  return 0;
}

