//
// Created by shivam on 12/29/19.
//

#include "iostream"
#include <bits/stdc++.h>
#include "vector"

using namespace std;

int myAtoi(string str) {

  int x = 0;
  bool sign = true, num = false;
  long long ten = 10, r;
  for (int i = 0; i < str.length(); i++) {
    if (str[i] == ' ' && num == false)
      continue;
    else if (str[i] == '+' && x == 0 && num == false && str[i + 1] >= 48 && str[i + 1] <= 57)
      sign = true;
    else if (str[i] == '-' && x == 0 && num == false && str[i + 1] >= 48 && str[i + 1] <= 57)
      sign = false;
    else if (str[i] >= 48 && str[i] <= 57) {
      num = true;
      r = (x * ten + str[i] - 48);
      if ((sign ? 1 : -1) * r >= INT_MAX)
        return INT_MAX;
      else if ((sign ? 1 : -1) * r <= INT_MIN)
        return INT_MIN;
      x = r;
    } else
      break;
  }
  return (sign ? 1 : -1) * x;
}


int main() {
//    cout << "here";


  assert(myAtoi("42") == 42);
  assert(myAtoi("   -42") == -42);
  assert(myAtoi("4193 with words") == 4193);
  assert(myAtoi("words and 987") == 0);
  assert(myAtoi("-91283472332") == -2147483648);


  cout << "success";
  cin.get();
  cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  return 0;
}