#include <iostream>

using namespace std;

const int N = 1010;
int n, m;
int v[N], w[N], s[N];
int f[N][N];
bool FLAG = false;

/*
input:
4 5
1 2 3
2 4 1
3 4 3
4 5 2
output:
10
*/

void method2() {
  int cnt = 0;
  int v1[N], w1[N];
  cin >> n >> m;
  v1[0] = w1[0] = 0;
  for (int i = 1; i <= n; i ++) {
    int a, b, s;
    cin >> a >> b >> s;
    int k = 1;
    while (k <= s) {
      cnt ++;
      v1[cnt] = k * a;
      w1[cnt] = k * b;
      s -= k;
      k *= 2;
    }
    if (s > 0) {
      cnt ++;
      v1[cnt] = s * a;
      w1[cnt] = s * b;
    }
  }
  for (int i = 0; i <= m; i ++) f[0][i] = 0;
  for (int i = 1; i <= cnt; i ++) {
    for (int j = 1; j <= m; j ++) {
      if (v1[i] <= j) f[i][j] = max(f[i-1][j], f[i-1][j-v1[i]] + w1[i]);
      else f[i][j] = f[i-1][j];
    }
  }
  cout << f[cnt][m] << endl;
}

int main() {

  if (!FLAG) {
    method2();
    return 0;
  }

  cin >> n >> m;

  for (int i = 1; i <= n; i ++) cin >> v[i] >> w[i] >> s[i];

  for (int i = 0; i <= m; i ++) f[0][i] = 0;

  for (int i = 1; i <= n; i ++) {
    for (int j = 1; j <= m; j ++) {
      for (int k = 0; k <= s[i] && k * v[i] <= j; k ++) {
        f[i][j] = max(f[i][j], f[i-1][j-k*v[i]] + k*w[i]);
      }
    }
  }

  cout << f[n][m] << endl;
  return 0;
}