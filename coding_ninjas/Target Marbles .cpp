//
// Created by shivam on 5/14/20.
//

#include "iostream"
#include <bits/stdc++.h>
#include "vector"

using namespace std;


int main() {
//    cout << "here";
  int target{0}, n{0};
  cin >> n >> target;
  int *arr = new int[n];
  for (int j = 0; j < n; ++j) {
    cin >> arr[j];
  }
  for (int i = 0; i < n - 1; ++i) {
    if (arr[i] + arr[i + 1] == target) {
      printf("true\n%d %d", arr[i], arr[i + 1]);
      return 0;
    }
  }
  printf("false");
  delete[] arr;
  cout << "success";
  cin.get();
  cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  return 0;
}