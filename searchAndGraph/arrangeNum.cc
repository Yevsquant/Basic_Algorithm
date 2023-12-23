// DFS
#include <iostream>

using namespace std;

const int N = 10;
int path[N];
bool st[N];
int n;

void dfs (int u) { // u is position
  if (u > n) {
    for (int i = 1; i <= n; i ++) printf("%d ", path[i]);
    printf("\n");
  }

  for (int i = 1; i <= n; i ++) {
    if (!st[i]) {
      path[u] = i;
      st[i] = true;
      dfs(u + 1);
      st[i] = false; // easily missed
    }
  }
}
/*
input:
3
output:
1 2 3
1 3 2
2 1 3
2 3 1
3 1 2
3 2 1
*/
int main() {
  scanf("%d", &n);
  dfs(1);
}