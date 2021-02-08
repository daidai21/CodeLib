/* ****************************************************************************
 * File Name   : null_object_pattern_get_binary_tree_size.cpp
 * Author      : DaiDai
 * Mail        : daidai4269@aliyun.com
 * Created Time: 日  2/ 7 11:45:45 2021
 *************************************************************************** */

#include <iostream>

using namespace std;

// BUG

struct Node {
  Node(Node* left, Node* right) {
    this->left = left;
    this->right = right;
  }

  Node() {}

  ~Node() {
    this->left->~Node();
    this->right->~Node();
  }

  Node* left;
  Node* right;
};

int tree_node_num(Node* node) {
  cout << "{" << node->left << "}" << " " << "{" << node->right << "}";
  // return 0;
  return tree_node_num(node->left) + tree_node_num(node->right) + 1;
}

int tree_node_num(nullptr) {
  return 0;
}

int main(int argc, char* argv[]) {
  Node* root = new Node(
    nullptr,
    new Node(
      new Node(),
      new Node()
    )
  );

  cout << tree_node_num(root) << endl;


  delete root;

  return 0;
}
