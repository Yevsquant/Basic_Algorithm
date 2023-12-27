#include <iostream>

using namespace std;

const int N = 100010;
int primes[N], cnt = 0;
bool st[N];
int PICK_A_FUNCTION = 0;

void find_prime(int n) {
  if (!PICK_A_FUNCTION) {
    for (int i = 2; i <= n; i ++) {
      if (!st[i]) primes[cnt ++] = i;
      for (int j = i; j <= n; j += i) st[j] = true;
    }
  }

  if (PICK_A_FUNCTION == 1) {
    for (int i = 2; i <= n; i ++) {
      if (!st[i]) {
        primes[cnt ++] = i;
        for (int j = i; j <= n; j += i) st[j] = true;
      }
    }
  }

  if (PICK_A_FUNCTION == 2) { // Not recommand
    for (int i = 2; i <= n; i ++) {
      if (!st[i]) primes[cnt ++] = i;
      for (int j = 0; primes[j] <= n / i; j ++) {
        st[primes[j] * i] = true;
        if (i % primes[j] == 0) break;
      }
    }
  }
}
/*
input:
8
output:
4
*/
int main() {
  int n;
  cin >> n;
  find_prime(n);
  for (int i = 0; i < cnt; i ++) {
    cout << primes[i] << ' ';
  }
  cout << endl;
  return 0;
}