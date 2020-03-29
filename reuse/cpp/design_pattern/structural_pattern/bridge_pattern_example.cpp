#include <iostream>


// bridge implementation interface
class DrawAPI {
 public:
  virtual void draw_circle(int radius, int x, int y) = 0; // pure virtual function
};

// entity class
class RedCircle: public DrawAPI {
 public:
  virtual void draw_circle(int radius, int x, int y) {
    std::cout << "RedCircle::draw_circle() "
              << radius << " " << x << " " << y << std::endl;
  }
};

class GreenCircle: public DrawAPI {
 public:
  virtual void draw_circle(int radius, int x, int y) {
    std::cout << "GreenCircle::draw_circle() "
              << radius << " " << x << " " << y << std::endl;
  }
};

// create abstract shape class using DrawAPI
class Shape {
 public:
  virtual void draw() = 0; // pure virtual function

 protected:
  Shape(DrawAPI* draw_api) {
    this->draw_api = draw_api;
  }

 protected:
  DrawAPI* draw_api;
};

// create entity shape class
class Circle: public Shape {
 public:
  Circle(int x, int y, int radius, DrawAPI* draw_api) : Shape(draw_api) {
    this->x      = x;
    this->y      = y;
    this->radius = radius;
  }

  virtual void draw() {
    this->draw_api->draw_circle(radius, x, y);
  }

 private:
  int x;
  int y;
  int radius;
};


// using bridge pattern example
int main() {
  Shape* red_circle   = new Circle(100, 100, 10, new RedCircle());
  Shape* green_circle = new Circle(100, 100, 10, new GreenCircle());

  red_circle->draw();
  green_circle->draw();

  delete red_circle;
  delete green_circle;

  return 0;
}

