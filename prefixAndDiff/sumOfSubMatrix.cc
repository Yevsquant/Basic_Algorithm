#include <iostream>

using namespace std;

const int N = 1010;
int a[N][N], s[N][N], n, m, q;

/*
input:
3 4 3
1 7 2 4
3 6 2 8
2 1 2 3
1 1 2 2
2 1 3 4
1 3 3 4
output:
17
27
21
*/
int main() {
  int n, m, q;
  scanf("%d%d%d", &n, &m, &q);
  for (int i = 1; i <= n; i ++) {
    for (int j = 1; j <= m; j ++) {
      scanf("%d", &a[i][j]);
      s[i][j] = s[i - 1][j] + s[i][j - 1] + a[i][j] - s[i - 1][j - 1];
    }
  }

  while (q --) {
    int x1, y1, x2, y2;
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    printf("%d\n", s[x2][y2] - s[x2][y1 - 1] - s[x1 - 1][y2] + s[x1 - 1][y1 - 1]);
  }
}