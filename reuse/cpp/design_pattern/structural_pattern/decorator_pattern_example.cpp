// TODO

#include <iostream>


// create shape interface
class Shape {
 public:
  virtual void draw() = 0; // pure virtual function
};

// entity class with interface shape
class Rectangle: public Shape {
 public:
  virtual void draw() {
    std::cout << "Shape: Rectangle" << std::endl;
  }
};


class Circle: public Shape {
 public:
  virtual void draw() {
    std::cout << "Shape: Circle" << std::endl;
  }
};

// create abstract decorator class
class ShapeDecorator: public Shape {
 public:
  ShapeDecorator(Shape* decoratored_shape) {
    this->decoratored_shape = decoratored_shape;
  }

  virtual void draw() {
    this->decoratored_shape->draw();
  }

 protected:
  Shape* decoratored_shape;
};

// create entity class with ShapeDecorator
class RedShapeDecorator: public ShapeDecorator {
 public:
  RedShapeDecorator(Shape* decoratored_shape) :ShapeDecorator (decoratored_shape) { }

  virtual void draw() {
    this->decoratored_shape->draw();
    this->set_red_border(this->decoratored_shape);
  }

 private:
  void set_red_border(Shape* decoratored_shape) {
    std::cout << "Border Color: Red" << std::endl;
  }
};


// using decorator pattern example
int main() {
  Shape* circle = new Circle();
  ShapeDecorator* red_circle = new RedShapeDecorator(new Circle());
  ShapeDecorator* red_rectangle = new RedShapeDecorator(new Rectangle());

  std::cout << "\n" << "Circle with normal border" << std::endl;
  circle->draw();

  std::cout << "\n" << "Circle of red border" << std::endl;
  red_circle->draw();

  std::cout << "\n" << "Rectangle of red border" << std::endl;
  red_rectangle->draw();

  delete circle;
  delete red_circle;
  delete red_rectangle;

  return 0;
}

