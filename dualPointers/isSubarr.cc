#include <iostream>

using namespace std;

const int N = 100010;
int a[N], b[N];

/*
input:
3 5
1 3 5
1 2 3 4 5
output:
Yes
*/
int main() {
  int n, m, j = 0;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i ++) scanf("%d", &a[i]);
  for (int i = 0; i < m; i ++) scanf("%d", &b[i]);

  for (int i = 0; i < m; i ++) {
    if (j == n) break;
    if (a[j] == b[i]) {
      j ++;
      continue;
    }
  }
  if (j == n) printf("Yes\n");
  else printf("No\n");
  return 0;
}