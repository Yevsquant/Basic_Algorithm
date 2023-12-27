#include <iostream>
#include <queue>
#include <vector>
#include <list>
using namespace std;

const int N = 100010;
typedef pair<int, int> PII;
int dist[N];
bool st[N];
int n, m;

int spfa(vector<list<PII>> graph, int start, int end) {
  queue<PII> q;
  memset(dist, 0x3f, sizeof dist);
  dist[start] = 0;
  q.push({0,start});
  st[start] = true;
  while (q.size()) {
    PII p = q.front();
    q.pop();
    int t = p.second; // current point
    st[t] = false;
    for (PII i : graph[t]) {
      int j = i.first;
      if (dist[j] > dist[t] + i.second) {
        dist[j] = dist[t] + i.second;
        if (!st[j]) {
          st[j] = true;
          q.push({dist[j], j});
        }
      }
    }
  }
  if (dist[end] == 0x3f3f3f3f) return -1;
  else return dist[end];
}
/*
current solution has bug waiting for solving
input:
3 3
1 2 5
2 3 -3
1 3 4
output:
2
*/
int main() {
  scanf("%d%d", &n, &m);
  vector<list<PII>> graph(n);
  while (m --) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    graph[a].push_back({b,c});
  }
  int res = spfa(graph, 1, n);
  if (res == -1) puts("impossible");
  else printf("%d\n", res);

  return 0;
}
