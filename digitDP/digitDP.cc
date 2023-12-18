#include <stdlib.h>
#include <iostream>

using namespace std;

const int N = 12;
int a[N];
int f[N][10];

void print_array(int arr[], int n) {
  for (int i = 0; i < n; i ++) {
    cout << arr[i] << " ";
  }
  cout << endl;
  return;
}

void init() {
  for (int i = 0; i <= 9; i ++) f[1][i] = 1;
  for (int i = 2; i <= N; i ++) {
    for (int j = 0; j <= 9; j ++) {
      for (int k = 0; k <= 9; k ++) {
        if (abs(j - k) >= 2) f[i][j] += f[i-1][k];
      }
    }
  }
}

int dp(int x) {
  if (!x) return 0; // input is 0
  int cnt = 0;
  while (x) a[++cnt] = x % 10, x /= 10; // store the digits in an arr

  int res = 0, last = -1;
  for (int i = cnt; i > 0; i --) {
    for (int j = (i==cnt); j < a[i]; j ++) {
      if (abs(j - last) >= 2) res += f[i][j];
    }
    if (abs(a[i] - last) < 2) break;
    last = a[i];
    if (i == 1) res ++;
  }

  for (int i = 1; i < cnt; i ++) {
    for (int j = 1; j <= 9; j ++) res += f[i][j];
  }

  return res;
}

int main() {
  memset(a, 0, sizeof(a));
  memset(f, 0, sizeof(f));
  init();

  int l, r;
  cin >> l >> r;
  cout << dp(r) - dp(l-1);
  return 0;
}