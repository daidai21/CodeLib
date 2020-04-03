#include <iostream>
#include <string>
#include <vector>


// interface
class Packing {
 public:
  virtual std::string pack() = 0;
};

class Item {
 public:
  virtual std::string name() = 0;
  virtual Packing* packing() = 0;
  virtual float price() = 0;
};

// entity class in packing interface
class Wrapper: public Packing {
 public:
  virtual std::string pack() {
    return "Wrapper";
  }
};

class Bottle: public Packing {
 public:
  virtual std::string pack() {
    return "Bottle";
  }
};

// abstract class in packing interface
class Burger: public Item {
 public:
  virtual Packing* packing() {
    return new Wrapper();
  }

  virtual float price() = 0;
};

class ColdDrink: public Item {
 public:
  virtual Packing* packing() {
    return new Bottle();
  }

  virtual float price() = 0;
};

// extend Burger and ColdDrink entity class
class VegBurger: public Burger {
 public:
  virtual float price() {
    return 25.0;
  }

  virtual std::string name() {
    return "Veg Burger";
  }
};

class ChickenBurger: public Burger {
 public:
  virtual float price() {
    return 50.0;
  }

  virtual std::string name() {
    return "Chicken Burger";
  }
};

class Coke: public ColdDrink {
 public:
  virtual float price() {
    return 30.0;
  }

  virtual std::string name() {
    return "Coke";
  }
};

class Pepsi: public ColdDrink {
 public:
  virtual float price() {
    return 35.0;
  }

  virtual std::string name() {
    return "Pepsi";
  }
};

// Meal class
class Meal {
 public:
  void add_item(Item* item) {
    this->items.push_back(item);
  }

  float get_cost() {
    float cost = 0.0;
    for (Item*& item : this->items) {
      cost += item->price();
    }
    return cost;
  }

  void show_items() {
    for (Item*& item : this->items) {
      std::cout << "Item: " << item->name() << ", "
                << "Packing: " << item->packing()->pack() << ", "
                << "Price: " << item->price() << std::endl;
    }
  }

 private:
  std::vector<Item* > items;
};

// MealBuilder class
class MealBuilder {
 public:
  Meal* prepare_veg_meal() {
    Meal* meal = new Meal();
    meal->add_item(new VegBurger);
    meal->add_item(new Coke);
    return meal;
  }

  Meal* prepare_non_veg_meal() {
    Meal* meal = new Meal();
    meal->add_item(new ChickenBurger());
    meal->add_item(new Pepsi());
    return meal;
  }
};

//
int main() {
  MealBuilder* meal_builder = new MealBuilder();

  Meal* veg_meal = meal_builder->prepare_veg_meal();
  std::cout << "Veg Meal" << std::endl;
  veg_meal->show_items();
  std::cout << "Total Cost: " << veg_meal->get_cost() << std::endl;

  std::cout << "\n" << std::endl;

  Meal* non_veg_meal = meal_builder->prepare_non_veg_meal();
  std::cout << "Non-Veg Meal" << std::endl;
  non_veg_meal->show_items();
  std::cout << "Total Cost: " << non_veg_meal->get_cost() << std::endl;

  delete meal_builder;
  delete veg_meal;
  delete non_veg_meal;

  return 0;
}

