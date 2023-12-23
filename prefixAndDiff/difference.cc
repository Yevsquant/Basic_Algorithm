#include <iostream>

using namespace std;

const int N = 100010;
int s[N], b[N];

/*
input:
6 3
1 2 2 1 2 1
1 3 1
3 5 1
1 6 1
output:
3 4 5 3 4 2
*/
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i ++) {
    scanf("%d", &s[i]);
    b[i] = s[i] - s[i - 1];
  }

  while (m --) {
    int l, r, c;
    scanf("%d%d%d", &l, &r, &c);
    b[l] += c;
    b[r + 1] -= c;
  }

  for (int i = 1; i <= n; i ++) {
    b[i] += b[i - 1];
    printf("%d ", b[i]);
  }

  return 0;
}