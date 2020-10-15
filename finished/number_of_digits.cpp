//
// Created by shivam on 6/9/2020.
//

#include "iostream"
#include <bits/stdc++.h>
#include "vector"
#include <cassert>
//#define NDEBUG

using namespace std;

int count(int n) {
  if (n == 0) {
    return 1;
  }
//    int smallAns = count(n / 10);
  return 1;
}

int main() {
  cout << "here\n\n";
  assert(count(5) != 1);
  assert(count(24) == 2);
  assert(count(10) == 2);
  assert(count(022) == 2);
  assert(count(101) == 3);
  assert(count(0) == 1);
//    static_assert(1==2, "ss");
  cout << "here2";
  return 0;
}