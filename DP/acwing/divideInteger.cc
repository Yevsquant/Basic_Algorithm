#include <iostream>

using namespace std;

// f[i][j] -> f[n][n]
// i: integer used; j: goal
int f[1010][1010];

/*
input:
5
output:
7
*/
int main() {
  int n;
  int mod = 1e9 + 7;
  cin >> n;
  f[0][0] = 1;

  for (int i = 1; i <= n; i ++) {
    for (int j = 0; j <= n; j ++) {
      f[i][j] = f[i-1][j] % mod;
      if (j >= i) f[i][j] = (f[i-1][j] + f[i][j-i]) % mod;
    }
  }

  cout << f[n][n] << endl;
  return 0;
}