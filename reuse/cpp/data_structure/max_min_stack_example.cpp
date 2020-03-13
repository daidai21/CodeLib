

#include "max_min_stack.hpp"

#include <iostream>

using namespace std;


int main() {
  MaxStack<int> ms;
  ms.push(1);
  cout << ms.get_max() << endl;
  ms.push(2);
  cout << ms.get_max() << endl;
  ms.pop();
  cout << ms.get_max() << endl;
  ms.push(234);
  cout << ms.get_max() << endl;
  ms.push(122);
  cout << ms.get_max() << endl;
  ms.pop();
  cout << ms.get_max() << endl;
  ms.push(234);
  cout << ms.get_max() << endl;
  ms.push(122);
  cout << ms.get_max() << endl;

  return 0;
}

