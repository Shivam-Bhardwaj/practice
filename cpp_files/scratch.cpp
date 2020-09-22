//
// Created by shivam on 9/21/20.
//

#include "iostream"
#include "any"
#include "vector"
#include "cassert"
#include "algorithm"

using namespace std;

vector<int> findThreeLargestNumbers(vector<int> array) {
  // Write your code here.
  vector<int> result{array.begin(), array.begin() + 3};
  sort(result.begin(), result.end());
  for (int i = 3; i < array.size(); ++i) {
    if (result.at(0) < array.at(i)) {
      result[0] = array.at(i);
      sort(result.begin(), result.end());
    }
  }
  return result;
}


int main() {
  vector<int> expected{18, 141, 541};
  assert(findThreeLargestNumbers(
    {141, 1, 17, -7, -17, -27, 18, 541, 8, 7, 7}) == expected);
}