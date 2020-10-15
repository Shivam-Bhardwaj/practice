//
// Created by shivam on 9/21/20.
//

#include "iostream"
#include "any"
#include "vector"
#include "cassert"
#include "algorithm"

using namespace std;

vector<vector<int>> threeNumberSum(vector<int> array, int targetSum) {
  // Write your code here.
  vector<vector<int>> result;
  sort(array.begin(), array.end());
  for (size_t i = 0; i < array.size(); ++i) {
    size_t left_pointer{i + 1}, right_pointer{array.size() - 1};
    while (left_pointer < right_pointer) {
      int current_sum = array.at(left_pointer) + array.at(i) + array.at(right_pointer);
      if (current_sum < targetSum) {
        left_pointer++;
      } else if (current_sum > targetSum) {
        right_pointer--;
      } else {
        result.push_back({array.at(i), array.at(left_pointer), array.at(right_pointer)});
        left_pointer++;
        right_pointer--;
      }
    }
  }
  return result;
}


int main() {
  vector<vector<int>> expected{{-8, 2, 6},
                               {-8, 3, 5},
                               {-6, 1, 5}};
  assert(threeNumberSum({12, 3, 1, 2, -6, 5, -8, 6}, 0) == expected);
  cout << "hi";
}