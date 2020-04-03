#include <iostream>
#include <string>


// Shape interface
class Shape {
 public:
  virtual void draw() = 0;
};

// Shape entity class
class Rectangle: public Shape {
 public:
  virtual void draw() {
    std::cout << "Inside Rectangle::draw() method." << std::endl;
  }
};

class Square: public Shape {
 public:
  virtual void draw() {
    std::cout << "Inside Square::draw() method." << std::endl;
  }
};

class Circle: public Shape {
 public:
  virtual void draw() {
    std::cout << "Inside Circle::draw() method." << std::endl;
  }
};

// Color interface
class Color {
 public:
  virtual void fill() = 0;
};

// Color entity class
class Red: public Color {
 public:
  virtual void fill() {
    std::cout << "Inside Red::fill() method." << std::endl;
  }
};

class Green: public Color {
 public:
  virtual void fill() {
    std::cout << "Inside Green::fill() method." << std::endl;
  }
};

class Blue: public Color {
 public:
  virtual void fill() {
    std::cout << "Inside Blue::fill() method." << std::endl;
  }
};

// Shape and Color abstract factory
class AbstractFactory {
 public:
  virtual Color* get_color(std::string color_type) = 0;
  virtual Shape* get_shape(std::string shape_type) = 0;
};

// entity class
class ShapeFactory: public AbstractFactory {
 public:
  virtual Shape* get_shape(std::string shape_type) {
    if (shape_type == "CIRCLE") {
      return new Circle();
    } else if (shape_type == "RECTANGLE") {
      return new Rectangle();
    } else if (shape_type == "SQUARE") {
      return new Square();
    } else {
      return nullptr;
    }
  }

  virtual Color* get_color(std::string color_type) {
    return nullptr;
  }
};


class ColorFactory: public AbstractFactory {
 public:
  virtual Shape* get_shape(std::string shape_type) {
    return nullptr;
  }

  virtual Color* get_color(std::string color_type) {
    if (color_type == "RED") {
      return new Red();
    } else if (color_type == "GREEN") {
      return new Green();
    } else if (color_type == "BLUE") {
      return new Blue();
    } else {
      return nullptr;
    }
  }
};

// factory producer
class FactoryProducer {
 public:
  static AbstractFactory* get_factory(std::string factory_type) {
    if (factory_type == "SHAPE") {
      return new ShapeFactory();
    } else if (factory_type == "COLOR") {
      return new ColorFactory();
    } else {
      return nullptr;
    }
  }
};

//
int main() {
  FactoryProducer fp;


  AbstractFactory* shape_factory = fp.get_factory("SHAPE");
  Shape* shape;

  shape = shape_factory->get_shape("CIRCLE");
  shape->draw();
  shape = shape_factory->get_shape("RECTANGLE");
  shape->draw();
  shape = shape_factory->get_shape("SQUARE");
  shape->draw();

  delete shape;
  delete shape_factory;


  AbstractFactory* color_factory = fp.get_factory("COLOR");
  Color* color;

  color = color_factory->get_color("RED");
  color->fill();
  color = color_factory->get_color("GREEN");
  color->fill();
  color = color_factory->get_color("BLUE");
  color->fill();

  delete color;
  delete color_factory;


  return 0;
}

