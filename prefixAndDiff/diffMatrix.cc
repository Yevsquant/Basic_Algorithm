#include <iostream>

using namespace std;

const int N = 1010;
int a[N][N], d[N][N];

void insert(int x1, int y1, int x2, int y2, int c) {
  d[x1][y1] += c;
  d[x1][y2 + 1] -= c;
  d[x2 + 1][y1] -= c;
  d[x2 + 1][y2 + 1] += c;
  return;
}

/*
input:
3 4 3
1 2 2 1
3 2 2 1
1 1 1 1
1 1 2 2 1
1 3 2 3 2
3 1 3 4 1
output:
2 3 4 1
4 3 4 1
2 2 2 2
*/
int main() {
  int n, m, q;
  scanf("%d%d%d", &n, &m, &q);
  for (int i = 1; i <= n; i ++) {
    for (int j = 1; j <= m; j ++) {
      scanf("%d", &a[i][j]);
      insert(i, j, i, j, a[i][j]);
    }
  }

  while (q --) {
    int x1, y1, x2, y2, c;
    scanf("%d%d%d%d%d", &x1, &y1, &x2, &y2, &c);
    insert(x1, y1, x2, y2, c);
  }

  for (int i = 1; i <= n; i ++) {
    for (int j = 1; j <= m; j ++) {
      d[i][j] += d[i - 1][j] + d[i][j - 1] - d[i - 1][j - 1];
      printf("%d ", d[i][j]);
    }
    printf("\n");
  }

  return 0;
}