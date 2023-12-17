#include <stdlib.h>
#include <iostream>

using namespace std;

const int N = 12;
int a[N];
int f[N][10];

void print_array(int arr[], int n) {
  for (int i = 0; i < n; i ++) {
    cout << arr[i] << " ";
  }
  cout << endl;
  return;
}

void init() {
  for (int i = 0; i <= 9; i ++) f[1][i] = 1;
  for (int i = 2; i <= N; i ++) {
    for (int j = 0; j <= 9; j ++) {
      for (int k = 0; k <= 9; k ++) {
        if (abs(j - k) >= 2) f[i][j] += f[i-1][k];
      }
    }
  }
}

int main() {
  memset(a, 0, sizeof(a));
  memset(f, 0, sizeof(f));
  init();

  for (int i = 0; i < N; i ++) {
    for (int j = 0; j < 10; j ++) {
      cout << f[i][j] << " ";
    }
    cout << endl;
  }

  return 0;
}