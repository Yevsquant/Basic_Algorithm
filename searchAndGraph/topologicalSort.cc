#include <iostream>
#include <queue>
#include <vector>
#include <list>

using namespace std;

const int N = 100010;
int n, m; // n: num of nodes; m: num of edges
int d[N], pre[N];

int bfs(std::vector<std::list<int>> adjacencyList) {
  // find the starting node
  int cnt = 0;
  for (int i = 1; i <= n; i ++) {
    if (!pre[i]) {
      d[cnt++] = i;
    }
  }
  int start = d[0];
  if (start == -1) return -1;
  queue<int> q;
  q.push(start);

  while (q.size()) {
    int t = q.front();
    q.pop();
    for (int node : adjacencyList[t]) {
      pre[node] --;
      if (pre[node] == 0) {
        q.push(node);
        d[cnt++] = node;
      }
    }
  }
  if (d[n-1] == -1) return -1;
  return 0;
}
/*
input:
3 3
1 2
2 3
1 3
output:
1 2 3 (one possible output)
*/
int main() {
  memset(d, -1, sizeof(d));
  memset(pre, 0, sizeof(pre));
  scanf("%d%d", &n, &m);
  std::vector<std::list<int>> adjacencyList(n+1);
  for (int i = 0; i < m; i ++) {
    int a, b;
    scanf("%d%d", &a, &b);
    adjacencyList[a].push_back(b);
    pre[b] ++;
  } 
  if (bfs(adjacencyList)) printf("-1\n");
  else {
    for (int i = 0; i < n; i ++) printf("%d ", d[i]);
    printf("\n");
  }
  return 0;
}
