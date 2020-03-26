// XOR double linked list

// TODO: memory leak test in like-unix


#ifndef __XOR_LINKED_LIST_HPP__
#define __XOR_LINKED_LIST_HPP__


#include <iostream>
#include <cstdint>
#include <string>
#include <vector>
#include <cassert>


template <typename DataType>
class XORLinkedList {
 public:
  XORLinkedList();
  XORLinkedList(std::vector<DataType> datas);
  XORLinkedList(const XORLinkedList& ll);
  ~XORLinkedList();

  XORLinkedList& operator=(const XORLinkedList& ll);
  // const DataType& operator[](unsigned int idx) const; // TODO
  // DataType& operator[](unsigned int idx); // TODO: https://github.com/amarsgithub/XOR-Linked-List/blob/master/LinkedList.cpp#L96
  

 private:
  class Node {
   public:
    DataType data;
    Node*    npx; // XOR of next and previous node
  };

  Node* XOR(Node* a, Node* b) {
    return (Node* ) ((uintptr_t) (a) ^ (uintptr_t) (b));
  }

  // TODO: support reload
  // return try std::string(data) exception &data
  std::string str(DataType data);

 public:
  // idx in [0, XORLinkedList.size() - 1]
  // Insert a node before the ith node
  void insert(unsigned int idx, DataType data);
  // idx in [0, XORLinkedList.size() - 1]
  void remove(unsigned int idx);
  // idx in [0, XORLinkedList.size() - 1]
  void change(unsigned int idx, DataType data);
  DataType get(unsigned int idx);

  DataType front() const { return this->head->data; }
  DataType back()  const { return this->tail->data; }

  // void push_front(DataType data);
  // void pop_front();
  // void push_back(DataType data);
  // void pop_back();

  // if flag = true, print node from left to right
  void print_list(bool flag = true);
  unsigned int size() { return this->length; }

 private:
  Node*        head;
  Node*        tail;
  unsigned int length;
};

template <typename DataType>
XORLinkedList<DataType>::XORLinkedList() {
  this->head   = nullptr;
  this->head   = nullptr;
  this->length = 0;
}

template <typename DataType>
XORLinkedList<DataType>::XORLinkedList(std::vector<DataType> datas) {
  // loop insert to head from end to start on datas

  // for (int i = datas.size() - 1; i >= 0; --i) {
  //   this->insert(0, datas[i]);
  // }
  // this->length = datas.size();

  Node* prev = nullptr;
  bool is_first_node = true;
  for (int i = 0; i < datas.size(); ++i) {
    Node* new_node = new Node();
    new_node->data = datas[i];
    new_node->npx  = nullptr;
    if (prev != nullptr) {
      new_node->npx = this->XOR(prev, nullptr);
      prev->npx = this->XOR(this->XOR(prev->npx, nullptr), new_node);
    }
    prev = new_node;
    if (is_first_node) {
      is_first_node = false;
      this->head = new_node;
    }
  }
  this->tail = prev;
  this->length = datas.size();
}

template <typename DataType>
XORLinkedList<DataType>::XORLinkedList(const XORLinkedList& ll) {
  this->head   = ll.head;
  this->tail   = ll.tail;
  this->length = ll.length;
}

template <typename DataType>
XORLinkedList<DataType>::~XORLinkedList() {
  // delete all Node
  Node* prev = nullptr;
  Node* curr = this->head;
  Node* next = nullptr;
  while (curr != nullptr) {
    next->npx = this->XOR(prev, curr);
    delete prev;
    prev = curr;
    curr = next;
  }
  delete this->head;
  delete this->tail;
}

template <typename DataType>
XORLinkedList<DataType>& XORLinkedList<DataType>::operator=(const XORLinkedList& ll) {
  return *this;
}

template <typename DataType>
std::string XORLinkedList<DataType>::str(DataType data) {
  try {
    return std::to_string(data);
  } catch (...) {
    return std::to_string((unsigned long long int)& data);
  }
}

template <typename DataType>
void XORLinkedList<DataType>::insert(unsigned int idx, DataType data) {
  // if (idx == 0) {
  //   Node* new_node = new Node();
  //   new_node->data = data;
  //   new_node->npx = this->XOR(this->head, nullptr);
  //   if (this->head != nullptr) {
  //     Node* next = this->XOR((this->head)->npx, nullptr);
  //     (this->head)->npx = this->XOR(new_node, next);
  //   }
  //   this->head = new_node;
  //   this->length++;
  // } else {
  //   // TODO
  // }

  assert(idx > 0 && idx <= std::max((unsigned int) 1, this->length)); // check idx parameter range error

  Node* prev     = nullptr;
  Node* curr     = this->head;
  Node* temp     = nullptr;
  for (int i = 1; i < idx && curr != nullptr; ++i) {
    temp = curr;
    curr = this->XOR(prev, curr->npx);
    prev = temp;
  }
  Node* new_node = new Node();
  new_node->data = data;
  new_node->npx  = this->XOR(prev, curr);
  if (curr != nullptr) {
    curr->npx = this->XOR(new_node, this->XOR(prev, curr->npx));
  }
  if (prev != nullptr) {
    prev->npx = this->XOR(this->XOR(prev->npx, curr), new_node);
  }
  if (idx == 1) {
    this->head = new_node;
  }
  this->length++;
}

template <typename DataType>
void XORLinkedList<DataType>::remove(unsigned int idx) {
  assert(idx >= 0 && idx < this->length); // check idx parameter range error

  Node* curr = this->head;
  Node* prev = nullptr;
  Node* next = nullptr;
  Node* temp = nullptr;
  for (int i = 0; i < idx && curr != nullptr; ++i) {
    temp = curr;
    curr = this->XOR(prev, curr->npx);
    prev = temp;
  }
  next = this->XOR(prev, curr->npx);
  if (prev != nullptr) {
    prev->npx = this->XOR(this->XOR(prev->npx, curr), next);
  }
  if (next != nullptr) {
    next->npx = this->XOR(prev, this->XOR(curr, next->npx));
  } else {
    this->tail = prev;
  }
  if (idx == 0) {
    this->head = next;
  }
  delete curr;
  this->length--;
}

template <typename DataType>
void XORLinkedList<DataType>::change(unsigned int idx, DataType data) {
  assert(idx >= 0 && idx < this->length); // check idx parameter range error

  Node* curr = this->head;
  Node* prev = nullptr;
  Node* temp = nullptr;
  for (int i = 0; i < idx && curr != nullptr; ++i) {
    temp = curr;
    curr = this->XOR(prev, curr->npx);
    prev = curr;
  }
  curr->data = data;
}

template <typename DataType>
DataType XORLinkedList<DataType>::get(unsigned int idx) {
  assert(idx >= 0 && idx < this->length); // check idx parameter range error

  Node* curr = this->head;
  Node* prev = nullptr;
  Node* temp = nullptr;
  for (int i = 0; i < idx && curr != nullptr; ++i) {
    temp = curr;
    curr = this->XOR(prev, curr->npx);
    prev = curr;
  }
  return curr->data;
}

template <typename DataType>
void XORLinkedList<DataType>::print_list(bool flag) {
  if (flag) {
    std::cout << "*****  XORLinkedList<DataType>::print_list(true)  *****" << std::endl;
    Node* curr = this->head;
    Node* prev = nullptr;
    Node* next;
    while (curr != nullptr) {
#ifdef DEBUG
      std::cout << this->str(curr->data) << "[" << static_cast<void *>(curr) << "," << static_cast<void *>(curr->npx) << "]";
#else
      std::cout << this->str(curr->data);
#endif
      next = this->XOR(prev, curr->npx);
      prev = curr;
      curr = next;
      if (curr != nullptr) {
        std::cout << "  <->  ";
      }
    }
    std::cout << std::endl;
  } else {
    // BUG
    /*
    std::cout << "*****  XORLinkedList<DataType>::print_list(false)  *****" << std::endl;
    std::cout << this->tail->data << " " << this->tail->npx << std::endl;
    // prev (head) -> curr -> next (tail)
    Node* prev = nullptr;
    Node* curr = this->tail;
    Node* next = nullptr;
    while (curr != nullptr) {
      std::cout << this->str(curr->data) << "[" << "]";

      Node* temp = curr;
      curr = this->XOR(curr->npx, next);
      prev = temp;

      if (curr != nullptr) {
        std::cout << "  <->  ";
      }

      std::cout << static_cast<void *>(prev) << " " << static_cast<void *>(curr) << " " << static_cast<void *>(next) << std::endl;
    }
    std::cout << std::endl;
    */
  }
}


#endif // __XOR_LINKED_LIST_HPP__

