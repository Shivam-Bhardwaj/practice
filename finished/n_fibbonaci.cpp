//
// Created by shivam on 12/6/19.
//


#include "iostream"
#include <bits/stdc++.h>

using namespace std;

int getNthFib(int n) {
  // Write your code here.
  if (n == 1) return 0;
  if (n == 2) return 1;
  return getNthFib(n - 1) + getNthFib(n - 2);;
}

int main(void) {
  cout << "here";
  assert(getNthFib(6) == 5);

  cin.get();
  cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  return 0;
}

