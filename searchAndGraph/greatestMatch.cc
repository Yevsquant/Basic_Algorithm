#include <iostream>
#include <vector>
#include <list>

using namespace std;
const int N = 510;
int n1, n2, m;
int match[N];
bool st[N];

bool find(int x, vector<list<int>> graph) {
  for (int i : graph[x]) {
    if (!st[i]) {
      st[i] = true;
      if (match[i] == 0 || find(match[i], graph)) {
        match[i] = x;
        return true;
      }
    }
  }
  return false;
}
/*
input:
2 2 4
1 1
1 2
2 1
2 2
output:
2
*/
int main() {
  scanf("%d%d%d", &n1, &n2, &m);
  vector<list<int>> graph(n1+1);
  for (int i = 0; i < m; i ++) {
    int a, b;
    scanf("%d%d", &a, &b);
    graph[a].push_back(b);
  }
  int res = 0;
  for (int i = 1; i <= n1; i ++) {
    memset(st, false, sizeof st);
    if (find(i, graph)) res ++;
  }
  printf("%d\n", res);
  return 0;
}