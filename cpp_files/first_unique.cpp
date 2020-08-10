////
// Created by shivam on 12/26/19.
//


// Created by shivam on 12/26/19.
//

#include "iostream"
#include <bits/stdc++.h>
#include "vector"

using namespace std;

int firstUniqChar(string s) {
  unordered_map<char, int> m;
  for (int i = 0; i < s.size(); i++) {
    m[s[i]]++;
  }
  for (int j = 0; j < s.size(); ++j) {
    if (m[s[j]] == 1) return j;
  }
  return -1;
}

int main() {
//    cout << "here";


  assert(firstUniqChar("leetcode") == 0);
  assert(firstUniqChar("loveleetcode") == 2);
  assert(firstUniqChar("aaaa") == -1);

  cout << "success";
  cin.get();
  cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  return 0;
}