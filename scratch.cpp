//
// Created by shivam on 9/21/20.
//

#include "iostream"
#include "vector"
#include "cassert"
#include "algorithm"


using namespace std;

bool balancedBrackets(string str) {
  // Write your code here.
  vector<char> stack_;
  for (int i{0}; i < str.size(); i++) {
    char c = str.at(i);
    switch (c) {
      case '(': {
        stack_.push_back(c);
        break;
      }
      case '[': {
        stack_.push_back(c);
        break;
      }
      case '{': {
        stack_.push_back(c);
        break;
      }

      case ')': {
        if(stack_.empty()) return false;
        if (stack_.back() != '(') {
          return false;
        } else {
          stack_.pop_back();
        }
        break;
      }

      case ']': {
        if(stack_.empty()) return false;
        if (stack_.back() != '[') {
          return false;
        } else {
          stack_.pop_back();
        }
        break;
      }

      case '}': {
        if(stack_.empty()) return false;
        if (stack_.back() != '{') {
          return false;
        } else {
          stack_.pop_back();
        }
        break;
      }

      default:
        break;
    }
  }

  return stack_.empty();
}


int main() {
  {
    assert(balancedBrackets("([])(){}(())()()") == true);
    cout << "TEST 0 PASS";
  }
}

