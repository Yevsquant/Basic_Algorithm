#include <iostream>

using namespace std;

const int N = 110;
int f[N][N], v[N][N], w[N][N], s[N];
int n, m, k;

/*
input:
3 5
2
1 2
2 4
1
3 4
1
4 5
output:
8
*/
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i ++) {
    cin >> s[i];
    for (int j = 0; j < s[i]; j ++) {
      cin >> v[i][j] >> w[i][j];
    }
  }

  for (int i = 1; i <= n; i ++) {
    for (int j = 0; j <= m; j ++) {
      f[i][j] = f[i-1][j];
      for (int k = 0; k < s[i]; k ++) {
        if (j >= v[i][k]) f[i][j] = max(f[i-1][j], f[i-1][j-v[i][k]] + w[i][k]);
      }
    }
  }
  cout << f[n][m] << endl;
  return 0;
}