#include <iostream>
#include <queue>
#include <vector>
#include <list>

using namespace std;

const int N = 100010;
int n, m; // n: num of nodes; m: num of edges
int d[N];

int bfs(int start, int end, std::vector<std::list<int>> adjacencyList) {
  d[start] = 0;
  queue<int> q;
  q.push(start);

  while (q.size()) {
    int t = q.front();
    q.pop();
    for (int node : adjacencyList[t]) {
      if (d[node] == -1) {
        q.push(node);
        d[node] = d[t] + 1;
      }
    }
  }
  return d[end];
}
/*
input:
4 5
1 2
2 3
3 4
1 3
1 4
output:
1
*/
int main() {
  scanf("%d%d", &n, &m);
  std::vector<std::list<int>> adjacencyList(n+1);
  for (int i = 0; i < m; i ++) {
    int a, b;
    scanf("%d%d", &a, &b);
    adjacencyList[a].push_back(b);
  }
  memset(d, -1, sizeof(d));
  printf("%d\n", bfs(1, n, adjacencyList));
  return 0;
}
