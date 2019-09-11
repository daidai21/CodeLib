/* =============================================================================
> File Name: call_back_function.cc
> Author: DaiDai
> Mail: daidai4269@aliyun.com
> Created Time: Mon 09 Sep 2019 06:17:55 PM CST
============================================================================= */


#include <iostream>
#include <vector>
using namespace std;


void func(vector<int>& arr, void (*func_add)(vector<int>::iterator)) {
  for (int i = 0; i < arr.size(); ++i)
    func_add(arr.begin() + i);
}

void add_one(vector<int>::iterator id) {
  ++(*id);
}

int main() {
  vector<int> vec = {1, 2, 3, 4, 567, 345};
  for (int v : vec)
    cout << v << " ";
  cout << endl;

  func(vec, add_one);

  for (int v : vec)
    cout << v << " ";
  cout << endl;

  return 0;
}
