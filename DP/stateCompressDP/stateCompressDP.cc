#include <vector>
#include <stdlib.h>
#include <iostream>

using namespace std;

const int N = 1 << 11;
bool st[N];
int f[N][N];

void init(int n) { // n is for row
  for (int i = 0; i < 1 << n; i ++) {
    st[i] = true;
    int cnt = 0;
    for (int j = 0; j < n; j ++) {
      if (i >> j & 1) {
        if (cnt & 1) {
          st[i] = false;
          break;
        }
      } else {
        cnt ++;
      }
    }
    if (cnt & 1) st[i] = false;
  }
}

// f[i][j]: i: col; j: case
void dp(int m, int n) {
  memset(f, 0, sizeof f);
  f[0][0] = 1;
  for (int i = 1; i <= m; i ++) {
    for (int j = 0; j < 1 << n; j ++) {
      for (int k = 0; k < 1 << n; k ++) {
        if ((j&k) == 0 && st[j|k]) f[i][j] += f[i-1][k];
      }
    }
  }
  cout << f[m][0] << endl;
}

/* Mondriaan's dream
  example input:
  1 3
  2 4
  4 4
  2 11
  0 0
  output:
  0
  5
  36
  144
*/
int main() {
  int m, n;
  while (1) {
    cin >> m >> n;
    if (!m && !n) break;
    init(n);
    dp(m, n);
  }
  return 0;
}