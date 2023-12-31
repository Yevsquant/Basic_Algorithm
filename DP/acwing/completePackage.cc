#include <iostream>

using namespace std;

const int N = 1010;
int n, m;
int v[N], w[N];
int f[N][N];

/*
input:
4 5
1 2
2 4
3 4
4 5
output:
10
*/
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i ++) cin >> v[i] >> w[i];
  
  // init
  for (int i = 0; i <= m; i ++) f[0][i] = 0;

  for (int i = 1; i <= n; i ++) {
    for (int j = 1; j <= m; j ++) {
      for (int k = 0; k * v[i] <= j; k ++) {
        f[i][j] = max(f[i][j], f[i-1][j-k*v[i]] + k * w[i]);
      }
    }
  }
  cout << f[n][m] << endl;
}