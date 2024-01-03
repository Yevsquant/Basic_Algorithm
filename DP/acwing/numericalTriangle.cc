#include <iostream>

using namespace std;

const int N = 1010, INF = 1e9;
int n;
int a[N][N], f[N][N];
/*
input:
5
7
3 8
8 1 0
2 7 4 4
4 5 2 6 5
output:
30
*/
int main() {
  cin >> n;
  for (int i = 1; i <= n; i ++) 
    for (int j = 1; j <= i; j ++) cin >> a[i][j];
  
  // init
  for (int i = 0; i <= n; i ++) {
    for (int j = 0; j <= i + 1; j ++) f[i][j] = -INF;
  }
  f[1][1] = a[1][1];

  for (int i = 2; i <= n; i ++) {
    for (int j = 1; j <= i; j ++) {
      f[i][j] = max(f[i-1][j], f[i-1][j-1]) + a[i][j];
    }
  }
  int ans = f[n][1];
  for (int i = 1; i <= n; i ++) ans = max(ans, f[n][i]);
  cout << ans << endl;
  return 0;
}