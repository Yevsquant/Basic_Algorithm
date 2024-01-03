#include <iostream>
#include <vector>
#include <list>

using namespace std;

const int N = 6010;
int h[N], f[N][2];
bool hasRoot[N];

void dfs(int u, vector<list<int>> tree) {
  f[u][1] = h[u];
  for (auto i : tree[u]) {
    dfs(i, tree);
    f[u][1] += f[i][0];
    f[u][0] += max(f[i][0], f[i][1]);
  }
}

/*
input:
7
1
1
1
1
1
1
1
1 3
2 3
6 4
7 4
4 5
3 5
output:
5
*/
int main() {
  int n;
  cin >> n;
  vector<list<int>> tree(n+1);
  for (int i = 1; i <= n; i ++) {
    cin >> h[i];
  }
  for (int i = 0; i < n-1; i ++) {
    int a, b;
    cin >> a >> b;
    tree[b].push_back(a);
    hasRoot[a] = true;
  }

  int root = 1;
  while (hasRoot[root]) root ++;
  dfs(root, tree);
  cout << max(f[root][1], f[root][0]) << endl;
  return 0;
}