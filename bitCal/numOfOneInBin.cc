#include <iostream>

using namespace std;

const int N = 100010;
int a[N];
/*
input:
5
1 2 3 4 5
output:
1 1 2 1 2
*/
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i ++) scanf("%d", &a[i]);

  for (int i = 0; i < n; i ++) {
    int cnt = 0;
    while(a[i]) {
      cnt += a[i] & 1;
      a[i] >>= 1;
    }
    printf("%d ", cnt);
  }

  return 0;
}