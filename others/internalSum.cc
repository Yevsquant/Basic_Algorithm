#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> PII;
const int N = 300010;
int a[N], s[N];
vector<int> alls;
vector<PII> add, query;

int find(int x) {
  int l = 0, r = alls.size() - 1;
  while (l < r) {
    int mid = (l + r) >> 1;
    if (alls[mid] >= x) r = mid;
    else l = mid + 1;
  }
  return r + 1; // idx starts from 1
}
/*
input:
3 3
1 2
3 6
7 5
1 3
4 6
7 8
output:
8
0
5
*/
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i ++) {
    int x, c;
    scanf("%d%d", &x, &c);
    add.push_back({x, c});
    alls.push_back(x);
  }
  for (int i = 1; i <= m; i ++) {
    int l, r;
    scanf("%d%d", &l, &r);
    query.push_back({l, r});
    alls.push_back(l);
    alls.push_back(r);
  }

  sort(alls.begin(), alls.end());
  alls.erase(unique(alls.begin(), alls.end()), alls.end());
  for (auto i : add) {
    int x = find(i.first);
    a[x] += i.second;
  }

  for (size_t i = 1; i <= alls.size(); i ++) {
    s[i] = a[i] + s[i - 1];
  }

  for (auto i : query) {
    int l = find(i.first);
    int r = find(i.second);
    printf("%d\n", s[r] - s[l - 1]);
  }
  return 0;
}