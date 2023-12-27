#include <iostream>
using namespace std;

const int N = 210, M = 2e+10, INF = 1e9;
int n,m,k,x,y,z;
int d[N][N];

void floyd() {
  for (int l = 1; l <= n; l ++) {
    for (int i = 1; i <= n; i ++) {
      for (int j = 1; j <= n; j ++) {
        d[i][j] = min(d[i][j], d[i][l] + d[l][j]);
      }
    }
  }
}
/*
input:
3 3 2
1 2 1
2 3 2
1 3 1
2 1
1 3
ouput:
impossible
1
*/
int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 1; i <= n; i ++) {
    for (int j = 1; j <= n; j ++) {
      if (i == j) d[i][j] = 0;
      else d[i][j] = INF;
    }
  }
  while (m --) {
    scanf("%d%d%d", &x, &y, &z);
    d[x][y] = min(d[x][y], z);
  }
  floyd();
  while (k --) {
    scanf("%d%d", &x, &y);
    if (d[x][y] > INF / 2) puts("impossible");
    else printf("%d\n", d[x][y]);
  }

  return 0;
}