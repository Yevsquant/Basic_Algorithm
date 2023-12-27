#include <iostream>
#include <vector>

using namespace std;

const int N = 510;
int n, m;
int g[N][N];
int dist[N];
bool st[N];

int Dijlstra(int start, int end) {
  memset(dist, 0x3f, sizeof dist);
  dist[start] = 0;
  st[start] = true;
  int t = start;
  for (int j = 0; j < n; j ++) { // runs
    for (int i = 1; i <= n; i ++) {
      if (st[i]) continue;
      if (g[t][i] < 0x3f && dist[i] > dist[t] + g[t][i]) {
        dist[i] = dist[t] + g[t][i];
      }
    }
    int min_dist_pt = -1;
    int min_dist = -1;
    for (int i = 1; i <= n; i ++) {
      if (!st[i] && (min_dist == -1 || min_dist > dist[i])) {
        min_dist = dist[i];
        min_dist_pt = i;
      }
    }
    st[min_dist_pt] = true;
    t = min_dist_pt;
  }
  return dist[end] != 0x3f ? dist[end] : -1;
}
/*
input:
3 3
1 2 2
2 3 1
1 3 4
output:
3
*/
int main() {
  scanf("%d%d", &n, &m);
  memset(g, 0x3f, sizeof g);
  while (m --) {
    int x, y, z;
    scanf("%d%d%d", &x, &y, &z);
    g[x][y] = min(g[x][y], z);
  }
  int shortest_path = Dijlstra(1, n);
  printf("%d\n", shortest_path);
  return 0;
}