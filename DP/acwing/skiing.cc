#include <iostream>

using namespace std;
const int N = 310;
int n, m;
int f[N][N], g[N][N];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int dp(int x, int y) {
  int &v = f[x][y];
  if (v) return v;
  v = 1;
  for (int i = 0; i < 4; i ++) {
    int xx = x + dx[i];
    int yy = y + dy[i];
    if (xx >= 0 && yy >= 0 && xx < n && yy < m && g[x][y] < g[xx][yy]) {
      v = max(v, dp(xx, yy) + 1);
    }
  }
  return v;
}

/*
input:
5 5
1 2 3 4 5
16 17 18 19 6
15 24 25 20 7
14 23 22 21 8
13 12 11 10 9
output:
25
*/
int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i ++) {
    for (int j = 0; j < m; j ++) {
      cin >> g[i][j];
    }
  }

  memset(f, 0, sizeof f);
  int res = 0;
  for (int i = 0; i < n; i ++) {
    for (int j = 0; j < m; j ++) {
      res = max(res, dp(i, j));
    }
  }
  cout << res << endl;
  return 0;
}