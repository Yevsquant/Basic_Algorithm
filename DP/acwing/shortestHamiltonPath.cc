#include <iostream>

using namespace std;

const int N = 20, M = 1 << N;
// f[i][j]: i: situation, j: destination
int f[M][N], g[N][N];

/*
input:
5
0 2 4 5 1
2 0 6 5 3
4 6 0 8 3
5 5 8 0 5
1 3 3 5 0
output:
18
*/
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i ++) {
    for (int j = 0; j < n; j ++) cin >> g[i][j];
  }

  memset(f, 0x3f, sizeof(f));
  f[1][0] = 0;

  for (int i = 0; i < (1<<n); i ++) { // all situations
    for (int j = 0; j < n; j ++) { // destinations
      if (i>>j & 1) {
        for (int k = 0; k < n; k ++) {
          if (i>>k & 1) f[i][j] = min(f[i][j], f[i-(1<<j)][k] + g[k][j]);
        }
      }
    }
  }

  cout << f[(1<<n)-1][n-1] << endl;
  return 0;
}