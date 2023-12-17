#include <stdlib.h>
#include <iostream>

using namespace std;

const int N = 10;

void print_array(int arr[], int n) {
  for (int i = 0; i < n; i ++) {
    cout << arr[i] << " ";
  }
  cout << endl;
  return;
}

int main() {
  int cnt = 0;
  int x;
  int arr[N];
  cin >> x;
  while (x) {
    arr[cnt++] = x % 10;
    x /= 10;
  }
  print_array(arr, cnt);
}