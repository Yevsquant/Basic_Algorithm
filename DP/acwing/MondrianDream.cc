#include <iostream>
#include <vector>

using namespace std;

const int N = 12, M = 1 << N;
long long f[N][M];
bool st[M];
int m, n;

/*
input:
1 2
1 3
1 4
2 2
2 3
2 4
2 11
4 11
0 0
output:
1
0
1
2
3
5
144
51205
*/
int main() {
  vector<int> res;
  while (cin >> n >> m, n || m) {
    memset(st, false, sizeof st);
    for (int i = 0; i < (1 << n); i ++) {
      int cnt = 0;
      st[i] = true;
      for (int j = 0; j < n; j ++) {
        if ((i >> j) & 1) {
          if (cnt & 1) {
            st[i] = false; break;
          }
        } else cnt ++;
      }
      if (cnt & 1) st[i] = false;
    }

    memset(f, 0, sizeof f);
    f[0][0] = 1;
    for (int i = 1; i <= m; i ++) {
      for (int j = 0; j < (1 << n); j ++) {
        for (int k = 0; k < (1 << n); k ++) {
          if (!(j & k) && st[j|k]) f[i][j] += f[i-1][k];
        }
      }
    }

    res.push_back(f[m][0]);
  }
  for (auto i : res) cout << i << endl;
  return 0;
}