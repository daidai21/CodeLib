/* =============================================================================
> File Name: digraph_judge_tree.cpp
> Author: DaiDai
> Mail: daidai4269@aliyun.com
> Created Time: Tue 17 Dec 2019 12:18:32 PM CST
============================================================================= */


// TODO: test

#include <vector>

using namespace std;


/**
 * determine whether a digraph is a tree
 * 
 * edges: .
 * n: number of node
 */
bool is_valid_tree(const vector<pair<int, int>>& edges, int n) {
  if (!n)
    return true;
  vector<unordered_set<int>> nodes(n);
  set<int> nodes;  // node with in-degree 0
  for (auto a: edges) {
    nodes[a.first].insert(a.second);
    nodes.push(a.first);
    nodes.push(a.second);
  }

  unordered_set<int> visited;
  queue<int> Q;
  Q.push(0);
  map<int, int> node_;  // degree of entry each node
  while (!Q.empty()) {
    int cur = Q.front();
    Q.pop();
    if (visited.find(cur) != visited.end())
      return false;
    for (auto a: nodes[cur]) {
      Q.push(a);
      nodes[a].erase(cur);
    }
    visited.insert(cur);

    if (node_.find(a.first) != node_.end())
      node_[a.first]++;
    else
      node_[a.first] = 1;
    if (node_[a.first] > 1)
      return false;

    if (nodes.find(a.second) != nodes.end()) {
    nodes.erase(a.second);
    }
  }
  
  return n == visited.size() && nodes.size() == 1;
}
