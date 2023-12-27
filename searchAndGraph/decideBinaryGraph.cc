#include <iostream>
#include <vector>
#include <list>

using namespace std;

const int N = 100010 * 2;
int color[N];
int n, m;

bool dfs(int u, int c, vector<list<int>> graph) {
  color[u] = c;
  for (int i : graph[u]) {
    if (!color[i]) {
      if (!dfs(i, 3 - c, graph)) return false;
    } else if (color[i] && color[i] != 3 - c) return false;
  }
  return true;
}
/*
input:
4 4
1 3
1 4
2 3
2 4
output:
This is a binary graph!
*/
int main() {
  scanf("%d%d", &n, &m);
  vector<list<int>> graph(n+1);
  for (int i = 0; i < m; i ++) {
    int a, b;
    scanf("%d%d", &a, &b);
    graph[a].push_back(b);
  }
  for (int i = 1; i <= n; i ++) {
    if (!color[i]) {
      if (!dfs(i, 1, graph)) {
        puts("Not a binary graph!");
        return 0;
      }
    }
  }
  puts("This is a binary graph!");
  return 0;
}