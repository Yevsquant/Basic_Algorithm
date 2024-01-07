#include <iostream>

using namespace std;

long long qmi(long long a, int b, int p) {
  long long res = 1;
  while (b) {
    if (b & 1) res = res * a % p;
    b >>= 1;
    a = a * a % p;
  }
  return res;
}

/*
input:
2
3 2 5
4 3 9
output:
4 1
*/
int main() {
  int n;
  cin >> n;
  long long res[n];
  for (int i = 0; i < n; i ++) {
    long long a;
    int b, p;
    cin >> a >> b >> p;
    res[i] = qmi(a, b, p);
  }

  for (int i = 0; i < n; i ++) {
    cout << res[i] << " ";
  }
  cout << endl;
  return 0;
}