#include <iostream>
#include <unordered_map>

using namespace std;
const int mod = 1e9 + 7;
long long res = 1;

/*
input:
3
2
6
8
output:
252
*/
int main() {
  int n;
  unordered_map<int, int> f;
  cin >> n;
  while (n--) {
    int a;
    cin >> a;
    
    for (int i = 2; i <= a / i; i ++) {
      if (a % i == 0) {
        while (a % i == 0) {
          a /= i;
          f[i] ++;
        }
      }
    }
    if (a > 1) f[a] ++;
  }

  for (pair<int, int> x : f) {
    long long t = 1;
    int j = x.second, p = x.first;
    while (j --) {
      t = (t * p + 1) % mod;
    }
    res = res * t % mod;
  }

  cout << res << endl;
  return 0;
}