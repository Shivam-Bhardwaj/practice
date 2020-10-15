#include "iostream"
#include <bits/stdc++.h>
#include "vector"

using namespace std;

bool isAnagram(string s, string t) {
  if (s.size() != t.size()) return false;
  unordered_map<char, int> m;
  for (int i = 0; i < s.size(); ++i) {
    m[s[i]]++;
  }

  for (int j = 0; j < t.size(); ++j) {
    if (m.find(t[j]) == m.end()) return false;
    else m[t[j]]--;
  }
  for (auto i : m) {
    if (i.second != 0) return false;
  }
  return true;
}


int main() {
//    cout << "here";


  assert(isAnagram("anagram", "nagaram") == true);
  assert(isAnagram("rat", "car") == false);

  cout << "success";
  cin.get();
  cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  return 0;
}