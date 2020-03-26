#include "./xor_linked_list.hpp"


int main(int argc, char* argv[]) {
  XORLinkedList<int> ll;
  ll.insert(1, 10);
  ll.insert(1, 20);
  ll.insert(1, 30);
  ll.insert(1, 40);
  ll.print_list();
  ll.print_list(false);
  std::cout << "XORLinkedList<int>::size() " << ll.size() << std::endl;
  ll.remove(1);
  ll.print_list();
  ll.remove(2);
  ll.print_list();
  std::cout << "XORLinkedList<int>::get() " << "0 " << ll.get(0) << std::endl;
  std::cout << "XORLinkedList<int>::get() " << "1 " << ll.get(1) << std::endl;
  ll.change(0, 1);
  ll.change(1, 2);
  ll.print_list();
  std::cout << "XORLinkedList<int>::front() " << ll.front() << std::endl;
  std::cout << "XORLinkedList<int>::back() " << ll.back() << std::endl;
  // std::cout << "XORLinkedList<int>::get() " << "2 " << ll.get(2) << std::endl; // idx param range error

  return 0;
}

