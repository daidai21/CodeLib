#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <random>


class Shape {
 public:
  virtual void draw() = 0;
};


class Circle : public Shape {
 public:
  Circle(std::string color) : color(color) { }

  void set_x(int x) {
    this->x = x;
  }

  void set_y(int y) {
    this->y = y;
  }

  void set_radius(int radius) {
    this->radius = radius;
  }

  virtual void draw() {
    std::cout << "Circle: Draw() [Color: " << this->color
              << ", x: " << this->x
              << ", y: "  << this->y
              << ", radius: " << this->radius
              << "]" << std::endl;
  }

 private:
  std::string color;
  int         x;
  int         y;
  int         radius;
};

class ShapeFactory {
 public:
  ~ShapeFactory() = default;

  Shape* get_circle(std::string color);

 private:
  std::map<std::string, Shape*> circle_map;
};

Shape* ShapeFactory::get_circle(std::string color) {
  if (circle_map.find(color) != circle_map.end()) {
    return circle_map[color];
  }
  Circle* circle = new Circle(color);
  circle_map.insert(std::make_pair(color, circle));
  std::cout << "Creating circle of color : " << color << std::endl;
  return circle;
}


// main function
static std::vector<std::string> colors = {
    "Red", "Green", "Blue", "White", "Black"};
static std::string get_rand_color() {
  std::random_device rd;
  std::uniform_real_distribution<> dis(0, 1);
  return colors[(int) colors.size() * dis(rd)];
}

static int get_rand_x() {
  std::random_device rd;
  std::uniform_real_distribution<> dis(0, 1);
  return (int) (dis(rd) * 100);
}

static int get_rand_y() {
  std::random_device rd;
  std::uniform_real_distribution<> dis(0, 1);
  return (int) (dis(rd) * 100);
}

int main() {
  ShapeFactory* sf = new ShapeFactory();
  for (int i = 0; i < 20; ++i) {
    Circle* circle = (Circle*) sf->get_circle(get_rand_color());
    circle->set_x(get_rand_x());
    circle->set_y(get_rand_y());
    circle->set_radius(100);
    circle->draw();
  }

  delete sf;

  return 0;
}

