//
// Created by shivam on 6/9/2020.
//

#include "iostream"
#include <bits/stdc++.h>
#include "vector"

using namespace std;

void print(int n) {
  if (n > 1) {
    print(n - 1);
  }
  cout << n << " ";
}

int main() {
  cout << "here\n\n";
  print(6);

  cout << "here2";
  cin.get();
  cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  return 0;
}