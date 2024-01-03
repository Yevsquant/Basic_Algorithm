#include <iostream>

using namespace std;

/*
input:
4 5
acbd
abedc
output:
3
*/
int main() {
  int n, m;
  string s1 = " ", s2 = " ";
  cin >> n >> m;
  for (int i = 0; i < n; i ++) {
    char a;
    cin >> a;
    s1 += a;
  }
  for (int i = 0; i < m; i ++) {
    char a;
    cin >> a;
    s2 += a;
  }

  int f[n+1][m+1];
  memset(f, 0, sizeof f);

  for (int i = 1; i <= s1.size(); i ++) {
    for (int j = 1; j <= s2.size(); j ++) {
      f[i][j] = max(f[i-1][j], f[i][j-1]);
      if (s1[i] == s2[j])
        f[i][j] = max(f[i][j], f[i-1][j-1] + 1);
    }
  }
  cout << f[n][m] << endl;
  return 0;
}