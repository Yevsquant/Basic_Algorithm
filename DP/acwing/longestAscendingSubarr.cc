#include <iostream>
#include <vector>

using namespace std;

int dp(vector<int>& nums) {
  int n = nums.size();
  if (!n) return 0;

  vector<int> v;
  for (int i = 0; i < n; i ++) {
    int pos = lower_bound(v.begin(), v.end(), nums[i]) - v.begin();
    if (pos == v.size()) v.push_back(nums[i]);
    else v[pos] = nums[i];
  }

  return v.size();
}

/*
input:
7
3 1 2 1 8 5 6
output:
4
*/
int main() {
  int n;
  cin >> n;
  vector<int> a;
  for (int i = 0; i < n; i ++) {
    int b;
    cin >> b;
    a.push_back(b);
  }
  cout << dp(a) << endl;
  return 0;
}
