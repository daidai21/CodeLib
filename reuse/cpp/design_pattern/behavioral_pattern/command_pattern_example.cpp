#include <iostream>
#include <vector>
#include <string>


class Order {
 public:
  virtual void execute() = 0;
};


class Stock {
 public:
  Stock() : name("ABC"), quantity(10) {}

  void buy() {
   std::cout << "Stock [ Name: " << this->name
             << ", Quantity: " << this->quantity
             << " ] bought" << std::endl;
  }

  void sell() {
   std::cout << "Stock [ Name: " << this->name
             << ", Quantity: " << this->quantity
             << " ] sold" << std::endl;
  }

 private:
  std::string name;
  int         quantity;
};

class BuyStock: public Order {
 public:
  BuyStock(Stock* abc_stock) {
    this->abc_stock = abc_stock;
  }

  void execute() {
    this->abc_stock->buy();
  }

 private:
  Stock* abc_stock;
};

class SellStock: public Order {
 public:
  SellStock(Stock* abc_stock) {
    this->abc_stock = abc_stock;
  }

  void execute() {
    this->abc_stock->sell();
  }

 private:
  Stock* abc_stock;
};

class Broker {
 public:
  void take_order(Order* order) {
    this->order_list.push_back(order);
  }

  void place_orders() {
    for (Order*& order : this->order_list) {
      order->execute();
    }
    this->order_list.clear();
  }

 private:
  std::vector<Order* > order_list;
};

int main() {
  Stock* abc_stock = new Stock();

  BuyStock*  buy_stock_order  = new BuyStock(abc_stock);
  SellStock* sell_stock_order = new SellStock(abc_stock);

  Broker* broker = new Broker();
  broker->take_order(buy_stock_order);
  broker->take_order(sell_stock_order);

  broker->place_orders();

  delete abc_stock;
  delete buy_stock_order;
  delete sell_stock_order;
  delete broker;

  return 0;
}

