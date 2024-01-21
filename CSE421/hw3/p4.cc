#include <iostream>
#include <random>
#include <vector>

using namespace std;

// helper
template<typename T>
void printVector(vector<pair<T, T>>& a) {
  for (auto i : a) {
    cout << "(" << i.first << ", " << i.second << ") ";
  }
  cout << endl;
}

template <typename T>
void quick_sort(vector<pair<T, T>>& q, int l, int r) {
  if (l >= r) return;
  int i = l - 1;
  int j = r + 1;
  double mid = q[(l + r) >> 1].second;

  while (i < j) {
    while (q[++i].second < mid);
    while (q[--j].second > mid);
    if (i < j) swap(q[i], q[j]);
  }

  quick_sort(q, l, j);
  quick_sort(q, j+1, r);
}

// n: number of intervals
vector<pair<double, double>> randomIntervalGenerator(int n) {
  // Store intervals
  vector<pair<double, double>> res;

  // Create a random number generator engine
  random_device rd;
  mt19937 gen(rd());

  // Uniform distribution in [0.0, 1.0)
  uniform_real_distribution<double> distr(0.0, 1.0);

  for (int i = 0; i < n; i ++) {
    double x = distr(gen);
    double y = distr(gen);
    if (x > y) swap(x, y);
    res.push_back({x, y});
  }
  return res;
}

vector<pair<double, double>> edf(vector<pair<double, double>> intervals) {
  vector<pair<double, double>> res;
  double end = -1.0;
  quick_sort(intervals, 0, intervals.size()-1); // O(nlogn)
  for (auto interval : intervals) { // O(n)
    if (end < interval.first) {
      res.push_back(interval);
      end = interval.second;
    }
  }
  return res;
}

vector<pair<double, double>> sif(vector<pair<double, double>> intervals) {
  vector<pair<double, double>> res;

  // Sort intervals by the length of interval
  sort(intervals.begin(), intervals.end(), [](const auto& lhs, const auto& rhs) {
    return lhs.second - lhs.first < rhs.second - rhs.first;
  });

  for (auto interval : intervals) { // O(n^2)
    if (res.empty()) res.push_back(interval);
    else {
      bool isIntersect = false;
      for (auto i : res) {
        if (!(interval.first > i.second || interval.second < i.first)) {
          isIntersect = true;
          break;
        }
      }
      if (!isIntersect) res.push_back(interval);
    }
  }

  return res;
}

vector<pair<double, double>> fif(vector<pair<double, double>> intervals) {
  vector<pair<double, double>> res;
  vector<pair<int, int>> tmp; // Record of intersections of each interval

  // Record the intersections (O(n^2))
  for (size_t i = 0; i < intervals.size(); i ++) {
    int cnt = 0;
    for (size_t j = 0; j < intervals.size(); j ++) {
      if (!(intervals[i].first >= intervals[j].second ||
            intervals[i].second <= intervals[j].first)) cnt ++;
    }
    tmp.push_back({i, cnt-1});
  }

  // Sort tmp
  /*
  sort(tmp.begin(), tmp.end(), [](const auto& lhs, const auto& rhs) {
    return lhs.second <= rhs.second;
  });
  */
 quick_sort(tmp, 0, tmp.size()-1);

  // Result (O(n^2))
  for (size_t i = 0; i < intervals.size(); i ++) {
    pair<double, double> interval = intervals[tmp[i].first];
    if (res.empty()) res.push_back(interval);
    else {
      bool isIntersect = false;
      for (auto j : res) {
        if (!(interval.first > j.second || interval.second < j.first)) {
                isIntersect = true;
                break;
        }
      }
      if (!isIntersect) res.push_back(interval);
    }
  }

  return res;
}

int main() {
  int runs, n;
  int avg_sol_size = 0;
  cin >> runs >> n;
  for (int i = 0; i < runs; i ++) {
    // Generate random intervals
    vector<pair<double, double>> intervals;
    intervals = randomIntervalGenerator(n);
    // printVector(intervals);

    // Answer of edf
    vector<pair<double, double>> ans_edf;
    ans_edf = edf(intervals);
    cout << "edf: " << ans_edf.size() << endl;
    // printVector(ans_edf);
    avg_sol_size += ans_edf.size();

    // Answer of sif
    vector<pair<double, double>> ans_sif;
    ans_sif = sif(intervals);
    cout << "sif: " << ans_sif.size() << endl;
    // printVector(ans_sif);

    // Answer of fif
    vector<pair<double, double>> ans_fif;
    ans_fif = fif(intervals);
    cout << "fif: " << ans_fif.size() << endl;
    // printVector(ans_fif);
    cout << endl;
  }
  //cout << "avg: " << avg_sol_size * 1.0 / runs << endl;

  return 0;
}