#include <iostream>

using namespace std;

const int N = 100010;
int n, q, a[N];

int findLeft(int x) {
  int l = 1, r = n;
  while (l < r) {
    int mid = (l + r) >> 1;
    if (x > a[mid]) l = mid + 1;
    else r = mid;
  }

  return r;
}

int findRight(int x) {
  int l = 1, r = n;
  while (l < r) {
    int mid = (l + r + 1) >> 1;
    if (x < a[mid]) r = mid - 1;
    else l = mid;
  }
  return l;
}

/* input:
  6 3
  1 2 2 3 3 4
  3
  4
  5
*/
int main() {
  scanf("%d%d", &n, &q);
  for (int i = 0; i < n; i ++) {
    scanf("%d", &a[i]);
  }
  while (q --) {
    int k;
    scanf("%d", &k);
    int left = findLeft(k);
    int right = findRight(k);
    if (a[left] != k) printf("-1 -1");
    else printf("%d %d", left - 1, right - 1);
  }

  return 0;
}