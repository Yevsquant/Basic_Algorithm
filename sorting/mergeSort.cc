#include <iostream>

using namespace std;

const int N = 100010;
int n, a[N], tmp[N];

void merge_sort(int q[], int l, int r) {
  if (l >= r) return;

  int mid = (l + r) >> 1, k = 0;
  merge_sort(q, l, mid), merge_sort(q, mid+1, r);

  int i = l, j = mid + 1;
  while (i <= mid && j <= r) {
    if (q[i] <= q[j]) tmp[k ++] = q[i ++];
    else tmp[k ++] = q[j ++];
  }
  while (i <= mid) tmp[k ++] = q[i ++];
  while (j <= r) tmp[k ++] = q[j ++];
  for (int i = l, k = 0; i <= r; i ++) q[i] = tmp[k ++];
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i ++) {
    scanf("%d", &a[i]);
  }
  merge_sort(a, 0, n - 1);
  for (int i = 0; i < n; i ++) {
    printf("%d ", a[i]);
  }
}