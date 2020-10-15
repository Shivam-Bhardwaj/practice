//
// Created by shivam on 9/21/20.
//

#include "iostream"
#include "any"
#include "vector"
#include "cassert"
#include "algorithm"

using namespace std;

bool isMonotonic(vector<int> array) {
  // Write your code here.
  if (array.size() < 3) return true;
  int idx{0};
  bool original_direction{false};
  while (idx < array.size()-1) {
    if (array.at(idx) == array.at(idx + 1)) {
      idx++;
    } else {
      original_direction = array.at(idx) < array.at(idx + 1);
      break;
    }
  }
  for (int i = 2; i < array.size(); ++i) {
    if (array[i] == array[i - 1]) {
      continue;
    }
    bool direction = array[i] > array[i - 1];
    if (direction != original_direction) {
      return false;
    }
  }
  return true;
}


int main() {
  vector<int> input = {1,1,1,1,1};
  bool expected = true;
  bool actual = isMonotonic(input);
  assert(expected == actual);
  cout << "hi";
}