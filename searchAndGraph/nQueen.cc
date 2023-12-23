// DFS
#include <iostream>

using namespace std;
const int N = 20;

int n;
char g[N][N];
bool col[N], dg[N], udg[N];

void dfs(int u) {
  if (u == n) {
    for (int i = 0; i < n; i ++) puts(g[i]);
    puts("");
    return;
  }

  int x = u;
  for (int y = 0; y < n; y ++) {
    if (!col[y] && !dg[y - x + n] && !udg[y + x]) {
      col[y] = dg[y - x + n] = udg[y + x] = true;
      g[x][y] = 'Q';
      dfs(x + 1);
      g[x][y] = '.';
      col[y] = dg[y - x + n] = udg[y + x] = false;
    }
  }
}
/*
input:
4
output:
.Q..
...Q
Q...
..Q.

..Q.
Q...
...Q
.Q..
*/
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i ++) {
    for (int j = 0; j < n; j ++) {
      g[i][j] = '.';
    }
  }

  dfs(0);
  return 0;
}