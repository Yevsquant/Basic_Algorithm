#include <iostream>

using namespace std;

const int N = 100010;
int primes[N], cnt, phi[N];
bool st[N];

/*
input:
3
3
6
8
output:
2
2
4
*/

long long euler1(int a) {
  long long res = a;
  for (int i = 2; i <= a / i; i ++) {
    if (a % i == 0) {
      res = res / i * (i - 1);
      while (a % i == 0) a /= i;
    }
  }
  if (a > 1) res = res / a * (a - 1);
  return res;
}

long long euler2(int a) {
  phi[1] = 1;
  memset(st, false, sizeof st);
  cnt = 0;
  for (int i = 2; i <= a; i ++) {
    if (!st[i]) {
      primes[cnt ++] = i;
      phi[i] = i - 1;
    }
    for (int j = 0; primes[j] <= a / i; j ++) {
      int t = primes[j] * i;
      st[t] = true;
      if (i % primes[j] == 0) {
        phi[t] = phi[i] * primes[j];
        break;
      }
      phi[t] = phi[i] * (primes[j] - 1);
    }
  }
  long long res = 0;
  for (int i = 1; i <= a; i ++) res += phi[i];
  return res;
}

int main() {
  int n;
  cin >> n;
  long long res[n];
  for (int i = 0; i < n; i ++) {
    int a;
    cin >> a;
    res[i] = euler2(a);
  }

  for (int i = 0; i < n; i ++) cout << res[i] << endl;
  return 0;
}