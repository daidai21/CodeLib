/* =============================================================================
> File Name: Trie_test.cpp
> Author: DaiDai
> Mail: daidai4269@aliyun.com
> Created Time: Tue 15 Oct 2019 10:45:03 PM CST
============================================================================= */


#include "Trie.hpp"

#include <iostream>
#include <string>

using namespace std;


int main() {
  Trie t1;

  t1.insert("asd");
  t1.insert("asd");
  t1.insert("asd");
  t1.insert("aasdf");
  t1.insert("aasdf");
  t1.insert("aasdf");
  t1.insert("aasdf");

  cout << "***** output word infor *****" << endl;
  cout << t1.search("as") << endl;
  cout << t1.search("asd") << endl;
  cout << t1.search("asdd") << endl;

  cout << t1.prefix_count("as") << endl;
  cout << t1.prefix_count("asd") << endl;
  cout << t1.prefix_count("asdd") << endl;


  return 0;
}
