#include <stdlib.h>
#include <iostream>

using namespace std;

const int N = 1e5 + 10;
int n, ans = N;
bool vis[N];
int h[N], e[2*N], ne[2*N], idx;

int add(int a, int b) {
  e[++idx] = b;
  ne[idx] = h[a];
  h[a] = idx;
  return 0;
}

int dfs(int u) {
  vis[u] = true;
  int size = 0;
  int sum = 1;
  for (int i = h[u]; i != -1; i = ne[i]) {
    int j = e[i];
    if (vis[j]) continue;
    int s = dfs(j);
    size = max(size, s);
    sum += s;
  }
  ans = min(ans, max(size, n - sum));
  return sum;
}

/* the barycenter of the trees
   example input:
   9
   1 4
   1 2
   2 6
   2 5
   6 3
   6 7
   7 9
   7 8
   output: 4
*/
int main() {
  memset(h, -1, sizeof(h));
  cin >> n;
  for (int i = 1; i < n; i ++) {
    int a, b;
    cin >> a >> b;
    add(a, b);
    add(b, a);
  }
  dfs(1);
  cout << ans << endl;
  return 0;
}