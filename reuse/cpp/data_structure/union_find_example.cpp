/* ****************************************************************************
 * File Name   : union_find_example.cpp
 * Author      : DaiDai
 * Mail        : daidai4269@aliyun.com
 * Created Time: 日 10/25 23:12:36 2020
 *************************************************************************** */

#include <climits>
#include <iostream>

using namespace std;

#define MAXN INT_MAX

int fa[MAXN];

/**
 * init
 */
// size == MAXN
void make_set(int size) {
  for (int i = 0; i < size; ++i)
    fa[i] = i;
  return;
}

/**
 * find
 */
int find(int x) {
  if (x != fa[x])
    fa[x] = find(fa[x]);
  return fa[x];
}

/**
 * union
 */
void union_set(int x, int y) {
  x = find(x);
  y = find(y);
  if (x == y)
    return;
  fa[x] = y;
}

int main(int argc, char* argv[]) {
  return 0;
}
