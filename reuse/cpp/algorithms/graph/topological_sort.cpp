/* =============================================================================
> File Name: topological_sort.cpp
> Author: DaiDai
> Mail: daidai4269@aliyun.com
> Created Time: Tue 07 Jan 2020 01:55:50 PM CST
============================================================================= */

#include <iostream>
#include <list>
#include <queue>

class Graph {
 private:
  int V;                // 顶点个数
  std::list<int>* adj;  // 邻接表
  std::queue<int> q;    // 维护一个入度为0的顶点的集合
  int* indegree;        // 记录每个顶点的入度

 public:
  Graph(int V);                // 构造函数
  ~Graph();                    // 析构函数
  void addEdge(int v, int w);  // 添加边
  bool topological_sort();     // 拓扑排序
};

Graph::Graph(int V) {
  this->V = V;
  adj = new std::list<int>[V];

  indegree = new int[V];  // 入度全部初始化为0
  for (int i = 0; i < V; ++i) {
    indegree[i] = 0;
  }
}

Graph::~Graph() {
  delete[] adj;
  delete[] indegree;
}

void Graph::addEdge(int v, int w) {
  adj[v].push_back(w);
  ++indegree[w];
}

bool Graph::topological_sort() {
  for (int i = 0; i < V; ++i) {
    if (indegree[i] == 0) {
      q.push(i);  // 将所有入度为0的顶点入队
    }
  }

  int count = 0;  // 计数，记录当前已经输出的顶点数
  while (!q.empty()) {
    int v = q.front();  // 从队列中取出一个顶点
    q.pop();

    std::cout << v << " ";  // 输出该顶点
    ++count;
    // 将所有v指向的顶点的入度减1，并将入度减为0的顶点入栈
    std::list<int>::iterator beg = adj[v].begin();
    for (; beg != adj[v].end(); ++beg) {
      if (!(--indegree[*beg])) {
        q.push(*beg);  // 若入度为0，则入栈
      }
    }
  }
  std::cout << std::endl;

  if (count < V)
    return false;  // 没有输出全部顶点，有向图中有回路
  else
    return true;  // 拓扑排序成功
}

int main() {
  Graph g(6);  // 创建图
  g.addEdge(5, 2);
  g.addEdge(5, 0);
  g.addEdge(4, 0);
  g.addEdge(4, 1);
  g.addEdge(2, 3);
  g.addEdge(3, 1);

  bool res = g.topological_sort();
  std::cout << res << std::endl;
  return 0;
}
