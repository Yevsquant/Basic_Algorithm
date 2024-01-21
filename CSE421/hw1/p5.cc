#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>
#include <random>
#include <iomanip>

using namespace std;

vector<vector<int>> M, W;
priority_queue<int, vector<int>, greater<int>> pq;

int find(vector<int> a, int x) {
  for (int i = 0; i < a.size(); i ++) {
    if (a[i] == x) return i + 1;
  }
  return -1;
}

/*
n: size
M, W: preference lists in form of matrix
pq: priority queue of m waiting for matching
*/
void stable_matching(int n, vector<vector<int>>& M, vector<vector<int>>& W,
                     priority_queue<int, vector<int>, greater<int>>& pq,
                     bool print_map) {
  vector<int> pos(n, 0); // the idx of all m's current preference to propose
  vector<bool> st(n, false); // state of all w, if w is matched with a m, stW[w-1] = true
  unordered_map<int, int> res;
  int MRank = 0, WRank = 0;
  while (!pq.empty()) {
    int m = pq.top();
    pq.pop();
    if (pos[m-1] > n) continue;
    int w = M[m-1][pos[m-1]];
    pos[m-1] ++;
    if (!st[w-1]) {
      res.insert({w,m});
      MRank += pos[m-1];
      WRank += find(W[w-1], m);

      st[w-1] = true;
    } else {
      int higher_ranked_m = res[w];

      // find the higher rank for w (m or res[w])
      for (int i = 0; i < n; i ++) {
        if (m == W[w-1][i]) { higher_ranked_m = m; break;}
        if (res[w] == W[w-1][i]) break;
      }

      if (higher_ranked_m == res[w]) { pq.push(m); continue;
      } else {
        pq.push(res[w]);
        int m_past = res[w];

        res.erase(w);
        MRank -= pos[m_past-1];
        WRank -= find(W[w-1], m_past);

        res.insert({w,higher_ranked_m});
        MRank += pos[m-1];
        WRank += find(W[w-1], m);
      }
    }

    // print the map
    if (print_map) {
      for (auto p : res) {
        cout << "(" << p.second << ", " << p.first << ") ";
      }
      cout << endl;
    }
  }
  cout << "MRank: " << MRank << " WRank: " << WRank << endl;
  cout << fixed << setprecision(3);
  cout << "MGoodness: " << MRank * 1.0 / n << endl;
  cout << "WGoodness: " << WRank * 1.0 / n << endl;
}

vector<vector<int>> generatePreferenceLists(mt19937& generator,
                                    int n, vector<int>& nums) {
  vector<vector<int>> res;
  for (int i = 0; i < n; i ++) {
    shuffle(nums.begin(), nums.end(), generator);
    res.push_back(nums);
  }
  return res;
}

void doStableMatching(int n) {
  vector<int> numbers;
  M.clear(), W.clear();

  // Create a vector of numbers
  for (int i = 1; i <= n; i++) {
    pq.push(i);
    numbers.push_back(i);
  }

  // Create a random number generator engine
  random_device rd;
  mt19937 mt(rd());

  // Shuffle the permutation of numbers randomly
  M = generatePreferenceLists(mt, n, numbers);
  W = generatePreferenceLists(mt, n, numbers);

  stable_matching(n, M, W, pq, false);
  return;

}

void printV(vector<int> nums) {
  for (size_t i = 0; i < nums.size(); i ++) {
    cout << nums[i] << " ";
  }
  cout << endl;
}

void printV2d(vector<vector<int>> a) {
  cout << "----------" << endl;
  for (auto i : a) printV(i);
  cout << "----------" << endl;
}

int main() {

  int n = 1;
  while (n > 0) {
    cin >> n;
    if (n <= 0) break;
    doStableMatching(n);
    cout << endl;
  }
  return 0;
}