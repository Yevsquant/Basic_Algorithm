#include <iostream>

using namespace std;

const int N = 100010;
int a[N], n, m;
/*
input:
5 3
2 1 3 6 4
1 2
1 3
2 4
output:
3
6
10
*/
int main() {
  scanf("%d%d", &n, &m);
  memset(a, 0, sizeof(int)*(n+1));
  for (int i = 1; i <= n; i ++) {
    scanf("%d", &a[i]);
    a[i] += a[i - 1];
  }

  while (m --) {
    int l, r;
    scanf("%d%d", &l, &r);
    printf("%d\n", a[r] - a[l - 1]);
  }

  return 0;
}