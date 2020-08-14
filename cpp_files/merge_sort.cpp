//
// Created by shivam on 8/14/2020.
//

#include "iostream"
#include <bits/stdc++.h>
#include "vector"

using namespace std;

void sort(vector<int> &array, size_t start = 0, size_t end = 0);

bool check(vector<int> &a);

int main() {
  vector<int> array{5, 4, 3, 2, 1, 1, 3, 2, 4};
  sort(array);
  for (int i : array) {
    cout << i;
  }
  if (check(array)) {
    cout << "\nsuccess";
  } else {
    cout << "\nfail";
  }
}

void sort(vector<int> &array, size_t start, size_t end) {
  //base case
  if (array.size() < 2) {
    return;
  }
  std::size_t mid = array.size() / 2;
  // recursive call
  sort(array, 0, mid - 1);
  sort(array, mid, array.size() - 1);

  // add
}

bool check(vector<int> &a) {
  for (int i = 0; i < a.size() - 1; ++i) {
    if (a.at(i) > a.at(i + 1)) {
      return false;
    }
  }
  return true;
}