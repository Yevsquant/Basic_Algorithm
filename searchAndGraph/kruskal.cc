#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100010;
int p[N];

struct E {
  int a;
  int b;
  int w;
  bool operator < (const E& rhs) {
    return this->w < rhs.w;
  }
} edg[N*2];
int res = 0, n, m, cnt = 0;
int find(int a) {
  if (p[a] != a) p[a] = find(p[a]);
  return p[a];
}

void klskr() {
  for (int i = 1; i <= m; i ++) {
    if (cnt >= n - 1) return;
    int pa = find(edg[i].a);
    int pb = find(edg[i].b);
    if (pa != pb) {
      res += edg[i].w;
      p[pa] = pb;
      cnt ++;
    }
  }
}
// operator bug
/*
input:
4 5
1 2 1
1 3 2
1 4 3
2 3 2
3 4 4
ouput:
6
*/
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i ++) p[i] = i;
  for (int i = 1; i <= m; i ++) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    edg[i] = {a, b, c};
  }
  sort(edg + 1, edg + m + 1);
  klskr();
  if (cnt < n - 1) puts("impossible");
  else printf("%d\n", res);
  return 0;
}