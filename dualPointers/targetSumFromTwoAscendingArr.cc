# include <iostream>

using namespace std;

const int N = 100010;
int a[N], b[N];
/*
input:
4 5 6
1 2 4 7
3 4 6 8 9
output:
1 1
*/
int main() {
  int n, m, x;
  scanf("%d%d%d", &n, &m, &x);
  for (int i = 0; i < n; i ++) scanf("%d", &a[i]);
  for (int i = 0; i < m; i ++) scanf("%d", &b[i]);

  for (int i = 0, j = m - 1; i < n; i ++) {
    while (j >= 0 && a[i] + b[j] > x) j --;
    if (j >= 0 && a[i] + b[j] == x) printf("%d %d\n", i, j);
  }
  return 0;
}