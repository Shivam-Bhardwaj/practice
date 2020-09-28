//
// Created by shivam on 9/27/20.
//

#include "iostream"
#include "any"
#include "vector"
#include "cassert"
#include "algorithm"

using namespace std;

vector<int> spiralTraverse(vector<vector<int>> array) {
  // Write your code here.
  vector<int> result;
  size_t start_column{0}, start_row{0}, end_column{array.at(0).size() - 1}, end_row{array.size() - 1};
  while (end_column >= start_column && end_row >= start_row) {
    if (end_column == start_column) {
      for (size_t i = start_row; i <= end_row; ++i) {
        result.push_back(array.at(i).at(end_column));
      }
      break;
    }
    if (end_row == start_row) {
      for (size_t i = start_column; i <= end_column; ++i) {
        result.push_back(array.at(start_row).at(i));
      }
      break;
    }

    /*RIGHT */
    for (size_t i = start_column; i <= end_column; ++i) {
      result.push_back(array.at(start_row).at(i));
    }

    /*DOWN*/
    for (size_t i = start_row + 1; i <= end_row; ++i) {
      result.push_back(array.at(i).at(end_column));
    }

    /*LEFT*/
    for (size_t i = end_column - 1 + 1; i-- > start_column;) {
      result.push_back(array.at(end_row).at(i));
    }

    /*UP*/
    for (size_t i = end_row - 1; i >= start_row + 1; --i) {
      result.push_back(array.at(i).at(start_column));
    }
    start_row++;
    end_row--;
    start_column++;
    end_column--;
  }
  return result;
}

int main() {
  vector<vector<int>> input = {
    {1,  2,  3},
    {12, 13, 14},
    {11, 16, 15},
    {10, 9,  8},
  };
  vector<int> expected = {1, 2, 3, 14, 15, 8, 9, 10, 11, 12, 13, 16};

  vector<int> actual = spiralTraverse(input);

  assert(expected == actual);

  input = {
    {1,  2,  3},
    {12, 13, 14},
    {11, 16, 15},
    {10, 9,  8},
  };
  expected = {1, 2, 3, 14, 15, 8, 9, 10, 11, 12, 13, 16};
  actual = spiralTraverse(input);
  assert(expected == actual);

  input = {
    {1,  2},
    {12, 13},
    {11, 16},
    {10, 9},
  };
  expected = {1, 2, 13, 16, 9, 10, 11, 12};
  actual = spiralTraverse(input);
  assert(expected == actual);

  input = {
    {1},
    {12},
    {11},
    {10},
  };
  expected = {1, 12, 11, 10};
  actual = spiralTraverse(input);
  assert(expected == actual);

  input = {{1,12,11,10}};
  expected = {1, 12, 11, 10};
  actual = spiralTraverse(input);
  assert(expected == actual);
  cout << "hi";
}