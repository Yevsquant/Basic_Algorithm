#include <iostream>

using namespace std;

const int N = 1010, M = 1e3 + 10;
int n, m;
char str[M][N];
int f[N][N];

int edit_distance(char a[], char b[]) {
  int la = strlen(a + 1), lb = strlen(b + 1);
  for (int i = 0; i <= la; i ++) f[i][0] = i;
  for (int i = 0; i <= lb; i ++) f[0][i] = i;

  for (int i = 1; i <= la; i ++) {
    for (int j = 1; j <= lb; j ++) {
      f[i][j] = min(f[i-1][j] + 1, f[i][j-1] + 1);
      f[i][j] = min(f[i][j], f[i-1][j-1] + (a[i] != b[j]));
    }
  }

  return f[la][lb];
}

/*
input:
3 2
abc
acd
bcd
ab 1
acbd 2
output:
1
3
*/
int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i ++) cin >> (str[i] + 1);
  while (m --) {
    int res = 0;
    char s[N];
    int limit;
    cin >> (s + 1) >> limit;
    for (int i = 0; i < n; i ++) {
      if (edit_distance(str[i], s) <= limit) res ++;
    }
    cout << res << endl;
  }
  return 0;
}