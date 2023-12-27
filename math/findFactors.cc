#include <iostream>
#include <vector>

using namespace std;

void find_factors(int x) {
  vector<int> res;
  for (int i = 1; i <= x / i; i ++) {
    if (x % i == 0) {
      res.push_back(i);
      if (x / i != i) res.push_back(x / i);
    }
  }
  sort(res.begin(), res.end());
  for (int i : res) cout << i << " ";
  cout << endl;

}
/*
input:
2
6
8
output:
1 2 3 6
1 2 4 8
*/
int main() {
  int n;
  cin >> n;
  while (n --) {
    int x;
    cin >> x;
    find_factors(x);
  }
}