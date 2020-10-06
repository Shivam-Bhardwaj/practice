//
// Created by shivam on 10/3/20.
//

#include "iostream"
#include "any"
#include "vector"
#include "cassert"
#include "algorithm"
#include "map"

using namespace std;

vector<int> helper(const string str, int left, int right){
  while(left >=0 && right < str.length()){
    if(str.at(left)!= str.at(right)){
      // return vector<int>{left+1, right};
      break;
    }
    left--;
    right++;

  }
  return vector<int>{left+1, right};
}

string longestPalindromicSubstring(string str) {
  // Write your code here.
  vector<int> result{0,1};
  for(int i = 1; i < str.length(); i++){
    vector<int> odd = helper(str, i-1, i+1);
    vector<int> even = helper(str, i-1, i);

    int odd_length = odd.at(1) - odd.at(0);
    int even_length = even.at(1) - even.at(0);
    vector<int> current_length = odd_length > even_length?odd:even;
    result = current_length.at(1) - current_length.at(0) > result.at(1) - result.at(0)?
             current_length:result;
  }
  return str.substr(result.at(0), result.at(1) - result.at(0));
}

int main() {
  {
    assert(longestPalindromicSubstring("abaxyzczyxf") == "xyzczyx");
    cout << "TEST 0 PASS";
  }
  {
    assert(longestPalindromicSubstring("abaxyzzyxf") == "xyzzyx");
    cout << "TEST 1 PASS";
  }
  {
    assert(longestPalindromicSubstring("aba") == "aba");
    cout << "TEST 2 PASS";
  }
  {
    assert(longestPalindromicSubstring("abcc") == "cc");
    cout << "TEST 3 PASS";
  }
  {
    assert(longestPalindromicSubstring("a") == "a");
    cout << "TEST 4 PASS";
  }
  {
    assert(longestPalindromicSubstring("aaaaabbbbbbb") == "bbbbbbb");
    cout << "TEST 5 PASS";
  }
}


