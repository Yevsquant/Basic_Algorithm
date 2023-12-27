#include <iostream>

using namespace std;

const int N = 510;
int g[N][N], d[N], pre[N];
int n, m;
bool st[N];

void prim() {
  memset(d, 0x3f, sizeof(d));
  int res = 0;
  d[1] = 0;
  for (int i = 0; i < n; i ++) {
    int t = -1;
    for (int j = 1; j <= n; j ++) {
      if (!st[j] && (t == -1 || d[j] < d[t])) t = j;
    }
    if (d[t] == 0x3f3f3f3f) {
      puts("impossible");
      return;
    }

    st[t] = true;
    res += d[t];
    for (int j = 1; j <= n; j ++) {
      if (d[j] > g[t][j] && !st[j]) {
        d[j] = g[t][j];
        pre[j] = t;
      }
    }
  }
  printf("%d\n", res);
  return;
}
/*
This solution is not intuitive ennough.
input:
4 5
1 2 1
1 3 2
1 4 3
2 3 2
3 4 4
ouput:
6
*/
int main() {
  memset(g, 0x3f, sizeof(g));
  scanf("%d%d", &n, &m);
  while (m --) {
    int a, b, w;
    scanf("%d%d%d", &a, &b, &w);
    g[a][b] = g[b][a] = min(g[a][b], w);
  }
  prim();
  // getPath();
  return 0;
}