#include <iostream>

using namespace std;

const int N = 100010;
int a[N];

int gcd(int a, int b) {
  return b ? gcd(b, a % b) : a;
}

/*
input:
2
3 6
4 6
output:
3
2
*/

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i ++) {
    int p, q;
    cin >> p >> q;
    a[i] = gcd(p,q);
  }

  for (int i = 0; i < n; i ++) cout << a[i] << " ";
  cout << endl;
  return 0;
}