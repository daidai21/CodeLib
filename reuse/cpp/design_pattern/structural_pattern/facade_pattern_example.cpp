#include <iostream>


// interface
class Shape {
 public:
  virtual void draw() = 0;
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

// create facade class
class ShapeMaker {
 public:
  ShapeMaker() {
    this->rectangle = new Rectangle();
    this->square    = new Square();
    this->circle    = new Circle();
  }

  ~ShapeMaker() {
    delete this->rectangle;
    delete this->square;
    delete this->circle;
  }

  void draw_circle() {
    this->circle->draw();
  }

  void draw_rectangle() {
    this->rectangle->draw();
  }

  void draw_square() {
    this->square->draw();
  }

 private:
  Shape* rectangle;
  Shape* square;
  Shape* circle;
};

int main() {
  ShapeMaker* shape_maker = new ShapeMaker();

  shape_maker->draw_circle();
  shape_maker->draw_rectangle();
  shape_maker->draw_square();

  delete shape_maker;

  return 0;
}

