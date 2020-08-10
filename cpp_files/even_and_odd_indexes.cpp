#include "iostream"
#include <bits/stdc++.h>
#include "vector"

using namespace std;


int main() {
//    cout << "here";
  int n;
  cin >> n;
  int *arr = new int[n];
  for (int j = 0; j < n; ++j) {
    cin >> arr[j];
  }
  int odd{0}, even{0};
  for (int i = 0; i < n; ++i) {
    if (i % 2 == 0) {
      if (arr[i] % 2 == 0)
        even += arr[i];
    } else {
      if (arr[i] % 2 == 1) {
        odd += arr[i];
      }
    }
  }
  cout << even << " " << odd;
  delete[] arr;
  cout << "success";
  cin.get();
  cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  return 0;
}