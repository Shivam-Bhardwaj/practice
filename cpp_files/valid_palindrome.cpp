#include "iostream"
#include <bits/stdc++.h>
#include "vector"

using namespace std;

bool isPalindrome(string s) {
  int j = s.size() - 1;
  int i = 0;
  while (i < j) {
    if (!isalnum(s[i])) {
      i++;
      continue;
    }
    if (!isalnum(s[j])) {
      j--;
      continue;
    }
    if (tolower(s[i]) != tolower(s[j])) return false;
    i++;
    j--;
  }
  return true;
}

int main() {
//    cout << "here";


  assert(isPalindrome("A man, a plan, a canal: Panama") == true);
  assert(isPalindrome("race a car") == false);
  assert(isPalindrome("0P") == false);
  cout << "success";
  cin.get();
  cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  return 0;
}