/* =============================================================================
> File Name: SkipList.hpp
> Author: DaiDai
> Mail: daidai4269@aliyun.com
> Created Time: Mon 02 Dec 2019 08:37:53 PM CST
============================================================================= */


#ifndef SKIPLIST_HPP_
#define SKIPLIST_HPP_


#include <cstdlib>
#include <iostream>


struct SkipListNode {
  int key;
  int value;
  int level;
  SkipListNode** next_nodes;
};


class SkipList {
 public:
  SkipList(int max_level_) {
    max_level = max_level_ > 0 ? max_level_ : 1;
    head = new SkipListNode;
    tail = new SkipListNode;
    head->next_nodes = new SkipListNode* [max_level];
    for (int i = 0; i < max_level; ++i)
      head->next_nodes[i] = tail;
  }

  ~SkipList() {
    SkipListNode* cur = nullptr;
    while (head->next_nodes[0] != tail) {
      cur = head->next_nodes[0];
      head->next_nodes[0] = head->next_nodes[0]->next_nodes[0];
      delete cur->next_nodes;
      delete cur;
    }
    delete head->next_nodes;
    delete head;
    delete tail;
  }

  void insert(int key, int value) {
    // find nodes before each node to be inserted on each level
    SkipListNode* update[max_level]; // FIXME: var name
    SkipListNode* cur = head;
    for (int i = 0; i < max_level; ++i) {
      if (cur->next_nodes[i] == tail || cur->next_nodes[i]->key > key)
        update[i] = cur;
      else {
        while (cur->next_nodes[i] != tail && cur->next_nodes[i]->key < key)
          cur = cur->next_nodes[i];
        update[i] = cur;
      }
    }

    // make a new SkipListNode for insert
    int level = random_level();
    SkipListNode* temp = new SkipListNode;
    temp->key = key;
    temp->value = value;
    temp->level = level;
    temp->next_nodes = new SkipListNode* [level + 1];
    // insert SkipListNode on each level
    // TODO
    for (int i = 0; i < max_level; ++i) {
      temp->next_nodes[i] = update[i]->next_nodes[i];
      update[i]->next_nodes[i] = temp;
    }
  }

  void erase(int key) {
    //
  }

  void modify(int key, int value) {
    //
  }

  SkipListNode* find(int key) {
    //
  }

  void display() {
    std::cout << "+++++ SkipList +++++" << std::endl;
    for (int i = 0; i < max_level; ++i) {
      std::cout << "Level " << i << ": ";
      // TODO
      std::cout << std::endl;
    }
  }

 protected:
  inline double uniform_random() {
    return rand() / double(RAND_MAX);
  }

  inline int random_level() {
    int level = 1;
    while (this->uniform_random() < 0.5 && level < this->max_level)
      level++;
    return level;
  }

 private:
  int max_level;
  SkipListNode* head;
  SkipListNode* tail;
};


#endif // SKIPLIST_HPP_


