//
// Created by shivam on 5/14/20.
//

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
  int sum{0};
  for (int i = 0; i < n/2; ++i) {
    sum = arr[i] + arr[n - 1 - i];
    printf("%d %d\n", sum/10, sum%10);
  }
  delete[] arr;
  cout << "success";
  cin.get();
  cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  return 0;
}