#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>

using namespace std;

/*
n: size
M, W: preference lists in form of matrix
pq: priority queue of m waiting for matching
*/
void stable_matching(int n, vector<vector<int>>& M, vector<vector<int>>& W,
                     priority_queue<int, vector<int>, greater<int>> pq) {
  unordered_map<int, int> res;
  // the idx of all m's current preference to propose
  vector<int> pos(n, 0);
  // state of all w, if w is matched with a m, stW[w-1] = true
  vector<bool> st(n, false);
  while (!pq.empty()) {
    int m = pq.top();
    pq.pop();
    if (pos[m] >= n) continue;
    int w = M[m][pos[m]];
    pos[m] ++;
    if (!st[w]) {
      res.insert({w,m});
      st[w] = true;
    } else {
      int higher_ranked_m = res[w];

      // find the higher rank (m or res[w])
      for (int i = 0; i < n; i ++) {
        if (m == W[w][i]) {
          higher_ranked_m = m;
          break;
        }
        if (res[w] == W[w][i]) break;
      }

      if (higher_ranked_m == res[w]) {
        pq.push(m);
        continue;
      } else {
        pq.push(res[w]);
        res.erase(w);
        res.insert({w,higher_ranked_m});
      }
    }

    // print the matched pairs
    for (auto p : res) {
      cout << "(" << p.second << ", " << p.first << ") ";
    }
    cout << endl;
  }
}

int main() { 
  int n = 4;
  vector<vector<int>> M = {{2,1,3,0}, {0,1,3,2}, {0,1,2,3}, {0,1,2,3}};
  vector<vector<int>> W = {{0,2,1,3}, {2,0,3,1}, {3,2,1,0}, {2,3,1,0}};
  priority_queue<int, vector<int>, greater<int>> pq;
  for (int i = 0; i < n; i ++) pq.push(i);

  stable_matching(n, M, W, pq);
  return 0;
}

/*
  n = 3;
  M = {{0, 1, 2}, {1, 0, 2}, {0, 2, 1}};
  W = {{1, 0, 2}, {0, 1, 2}, {2, 0, 1}};
  */