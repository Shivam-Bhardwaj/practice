#include "iostream"
#include <bits/stdc++.h>
#include "vector"

using namespace std;


int main() {
  int n{0};
  cin >> n;
  int **arr = new int *[n];
  for (int i = 0; i < n; ++i) {
    arr[i] = new int[n];
    for (int j = 0; j < n; ++j) {
      cin >> arr[i][j];
    }
  }
  int sum{0};
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      // check for diagonal 1
      if ((i == j) || ((i + j) == (n - 1)) || (j == 0) || (j == (n - 1)) || (i == 0) || (i == n - 1)) {
        sum += arr[i][j];
      }
    }
  }
  cout << sum;

  cin.get();
  cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  return 0;
}