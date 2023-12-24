// BFS
#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <string>

using namespace std;

int bfs(string start) {
  string end = "12345678x";
  queue<string> q;
  unordered_map<string, int> d;
  q.push(start);
  d[start] = 0;

  int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
  while (q.size()) {
    auto t = q.front();
    q.pop();
    int dis = d[t];
    if (t == end) return dis;

    int k = t.find('x');
    int x = k / 3, y = k % 3;

    for (int i = 0; i < 4; i ++) {
      int a = x + dx[i], b = y + dy[i];
      if (a >= 0 && a < 3 && b >= 0 && b < 3) {
        swap(t[k], t[a * 3 + b]);
        if (!d.count(t)) {
          d[t] = dis + 1;
          q.push(t);
        }
        swap(t[k], t[a * 3 + b]);
      }
    }
  }
  return -1;
}
/*
input:
2 3 4 1 5 x 7 6 8
output:
19
*/
int main() {
  string c, start;
  for (int i = 0; i < 9; i ++) {
    cin >> c;
    start += c;
  }
  printf("%d\n", bfs(start));
  return 0;
}