#ifndef TRIE_HPP_
#define TRIE_HPP_


#include <string>


struct Node {
  int count;
  bool is_end;
  struct Node* child[26];
};


class Trie {
 public:
  Trie();
  ~Trie(); // dfs delete

  void insert(std::string word);
  bool search(std::string word);
  int prefix_count(std::string prefix);

  void _del_all_node(Node* cur);

 public:
  Node* root;
};


Trie::Trie() {
  root = new Node();
  root->count = 0;
  root->is_end = false;
}

Trie::~Trie() {
  _del_all_node(root);
  delete root;
}

void Trie::insert(std::string word) {
  Node* cur = root;
  cur->count++;
  for (int i = 0; i < word.size(); ++i) {
    int letter = word[i] - 'a';
    if (cur->child[letter] == NULL)
      cur->child[letter] = new Node();
    cur->child[letter]->count++;
    cur = cur->child[letter];
  }
  cur->is_end = true;
}

bool Trie::search(std::string word) {
  Node* cur = root;
  for (int i = 0; i < word.size(); ++i) {
    int letter = word[i] - 'a';
    if (cur->child[letter] == NULL)
      return false;
    cur = cur->child[letter];
  }
  return cur->is_end;
}

int Trie::prefix_count(std::string prefix) {
  Node* cur = root;
  for (int i = 0; i < prefix.size(); ++i) {
    int letter = prefix[i] - 'a';
    if (cur->child[letter] == NULL)
      return 0;
    else
      cur = cur->child[letter];
  }
  return cur->count;
}

void Trie::_del_all_node(Node* cur) {
  if (cur == NULL)
    return ;
  for (int i = 0; i < 26; ++i) {
    if (cur->child[i] != NULL)
      _del_all_node(cur->child[i]);
    delete cur->child[i];
  }
}

#endif // TRIE_HPP_
