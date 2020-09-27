//
// Created by shivam on 9/21/20.
//

#include "iostream"
#include "any"
#include "vector"
#include "cassert"
#include "algorithm"

using namespace std;

int longestPeak(vector<int> array) {
  // Write your code here.
  if (array.size() < 2) return 0;
  size_t idx{1}, peak_length{0};

  while (idx < array.size() - 1) {
    bool is_peak = (array.at(idx) > array.at(idx - 1) && array.at(idx) > array.at(idx + 1));
    if (!is_peak) {
      idx++;
      continue;
    }
    size_t left{idx}, right{idx};
    while (left > 0) {
      if (array.at(left - 1) < array.at(left)) {
        left--;
      } else {
        break;
      }
    }
    while (right < array.size()-1) {
      if (array.at(right) > array.at(right + 1)) {
        right++;
      }else{
        break;
      }
    }
    peak_length = max(peak_length, right - left + 1);
    idx++;
  }
  return peak_length;
}


int main() {
  vector<int> input = {1, 2, 3, 4, 3, 2, 1};
  int expected = 7;
  int actual = longestPeak(input);
  assert(expected == actual);
  input = {};
  expected = 0;
  actual = longestPeak(input);
  assert(expected == actual);
  input = {1};
  expected = 0;
  actual = longestPeak(input);
  assert(expected == actual);
  input = {1, 1};
  expected = 0;
  actual = longestPeak(input);
  assert(expected == actual);
  input = {1, 1, 1};
  expected = 0;
  actual = longestPeak(input);
  assert(expected == actual);
  input = {1, 2, 3, 4};
  expected = 0;
  actual = longestPeak(input);
  assert(expected == actual);
  input = {1, 2, 3, 4, 3, 2, 1};
  expected = 7;
  actual = longestPeak(input);
  assert(expected == actual);
  input = {1, 2, 3, 2, 1, 0, 1, 2, 3, 4, 3, 2, 1};
  expected = 8;
  actual = longestPeak(input);
  assert(expected == actual);
  input = {1, 2, 3, 10, 2};
  expected = 5;
  actual = longestPeak(input);
  assert(expected == actual);

  cout << "hi";
}