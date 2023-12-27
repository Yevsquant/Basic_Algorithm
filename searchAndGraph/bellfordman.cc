#include <iostream>

using namespace std;

const int N = 510, M = 10010;
struct Edge {
  int a;
  int b;
  int w;
} e[M];
int dist[N], back[N];
int n, m, k;

int bellman_ford(int start, int end) {
  memset(dist, 0x3f, sizeof dist);
  dist[start] = 0;
  for (int i = 0; i < k; i ++) {
    memcpy(back, dist, sizeof dist);
    for (int j = 0; j < m; j ++) {
      int a = e[j].a, b = e[j].b, w = e[j].w;
      dist[b] = min(dist[b], back[a] + w);
    }
  }
  if (dist[end] > 0x3f3f3f3f / 2) return -1;
  else return dist[end];
}
/*
input:
3 3 1
1 2 1
2 3 1
1 3 3
output:
3
*/
int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 0; i < m; i ++) {
    int a, b, w;
    scanf("%d%d%d", &a, &b, &w);
    e[i] = {a, b, w};
  }
  int res = bellman_ford(1, n);
  if (res == -1) puts("impossible");
  else printf("%d\n", res);
  return 0;
}