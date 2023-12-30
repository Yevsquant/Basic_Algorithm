#include <iostream>

using namespace std;

const int N = 1010;
int n, m;
int v[N], w[N];
// g[i][j]: Set of choosing from the first i items
//          while the volume not exceed j;
//          Separate into two parts for calculate f[i][j]
//          with the ith item and without the ith item
// f[i][j]: from the first i items, choose the best
//          solution while the volume not exceed j
int f[N][N];
/*
input:
4 5
1 2
2 4
3 4
4 5
output:
8
*/
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i ++) {
    cin >> v[i] >> w[i];
  }

  // init
  for (int i = 0; i <= m; i ++) {
    f[0][i] = 0;
  }
  
  for (int i = 1; i <= n; i ++) {
    for (int j = 1; j <= m; j ++) {
      if (v[i] <= j) {
        f[i][j] = max(f[i-1][j], f[i-1][j-v[i]] + w[i]);
      } else f[i][j] = f[i-1][j];
    }
  }
  cout << f[n][m] << endl;
  return 0;
}