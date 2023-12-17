#include <stdlib.h>
#include <iostream>

using namespace std;

// luogu P1775
const int N=310;
int n; // num of balls
int a[N]; // costs of balls
int s[N]; // prefix sum
int f[N][N]; // f[l][r], the min cost from l to r

int main() {
  // preprocessing
  memset(f, 0x3f, sizeof(f));
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    s[i] = s[i-1] + a[i];
    f[i][i] = 0;
  }

  // dp
  for (int i = 2; i <= n; i++) { // length of intervals
    for (int l = 1; l+i-1 <= n; l++) { // starting pt
      int r = l+i-1;
      for (int k = l; k < r; k ++) {
        f[l][r] = min(f[l][r], f[l][k]+f[k+1][r]+s[r]-s[l-1]);
      }
    }
  }

  cout << f[1][n] << endl;
}