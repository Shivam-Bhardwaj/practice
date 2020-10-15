//
// Created by shivam on 12/26/19.
//

#include "iostream"
#include <bits/stdc++.h>
#include "vector"

using namespace std;

int reverse(int x) {
  int rev = 0;
  while (x != 0) {
    int pop = x % 10;
    x /= 10;
    if (rev > INT_MAX / 10 || (rev == INT_MAX / 10 && pop > 7)) return 0;
    if (rev < INT_MIN / 10 || (rev == INT_MIN / 10 && pop < -8)) return 0;
    rev = rev * 10 + pop;
  }
  return rev;
}

int main() {
//    cout << "here";
  cout << reverse(-2147483647) << endl;

  assert(reverse(-123) == -321);
  assert(reverse(3) == 3);
  assert(reverse(30) == 3);
  assert(reverse(-3) == -3);
  assert(reverse(-39) == -93);
  assert(reverse(-10) == -1);
  cout << "success";
  cin.get();
  cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  return 0;
}