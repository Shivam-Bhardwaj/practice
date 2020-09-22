//
// Created by shivam on 9/21/20.
//

#include "iostream"
#include "any"
#include "vector"
#include "cassert"
#include "algorithm"

using namespace std;

bool isPalindrome(string str) {
  // Write your code here.
  if (str.empty()) return true;
  std::size_t left{0}, right{str.length()-1};
  for (; left <right ;) {
    if (str.at(left++)!=str.at(right--)) return false;
  }
  return true;
}


int main() {
  assert(isPalindrome("aba"));
}