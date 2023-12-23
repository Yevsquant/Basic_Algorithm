#include <iostream>

using namespace std;

const int N = 100010;
int a[N], s[N];
/*
input:
6
4 2 2 1 3 5
output:
4
*/
int main() {
  int n, r = 0;
  scanf("%d", &n);
  for (int i = 0; i < n; i ++) {
    scanf("%d", &a[i]);
  }

  for (int i = 0, j = 0; i < n; i ++) {
    s[a[i]] ++; // better use map for elements in a are not pos int
    while (s[a[i]] > 1) --s[a[j ++]];
    r = max(r, i - j + 1);
  }

  printf("%d\n", r);
  return 0;
}