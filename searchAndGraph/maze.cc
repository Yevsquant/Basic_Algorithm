#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

const int N = 110;

typedef pair<int, int> PII;

int n, m;
int g[N][N], d[N][N];

int bfs() {
  queue<PII> q;
  q.push({0, 0});
  memset(d, -1, sizeof(d));
  d[0][0] = 0;

  int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
  while (q.size()) {
    PII t = q.front();
    q.pop();

    for (int i = 0; i < 4; i ++) {
      int x = t.first + dx[i], y = t.second + dy[i];
      if (x >= 0 && x < n && y >= 0 && y < m && g[x][y] == 0 && d[x][y] == -1) {
        d[x][y] = d[t.first][t.second] + 1;
        q.push({x, y});
      }
    }
  }
  return d[n-1][m-1];
}

/*
input:
5 5
0 1 0 0 0
0 1 0 1 0
0 0 0 0 0
0 1 1 1 0
0 0 0 1 0
output:
8
*/
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i ++) {
    for (int j = 0; j < m; j ++) {
      scanf("%d", &g[i][j]);
    }
  }
  printf("%d\n", bfs());
  return 0;
}