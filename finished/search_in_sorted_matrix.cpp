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

vector<int> searchInSortedMatrix(vector<vector<int>> matrix, int target) {
  // Write your code here.
  size_t row{0}, column{matrix.at(0).size() - 1};
  while (row < matrix.size() && column >= 0) {
    if (matrix.at(row).at(column) > target){
      column--;
    } else if(matrix.at(row).at(column) < target){
      row++;
    } else  return vector<int>{static_cast<int>(row), static_cast<int>(column)};
  }
  return vector<int>{-1, -1};
}


int main() {
  {
    vector<vector<int>> matrix{
      {1,  4,   7,   12,  15,  1000},
      {2,  5,   19,  31,  32,  1001},
      {3,  8,   24,  33,  35,  1002},
      {40, 41,  42,  44,  45,  1003},
      {99, 100, 103, 106, 128, 1004},
    };
    vector<int> expected{3, 3};
    assert(searchInSortedMatrix(matrix, 44) == expected);
    cout << "TEST 0 PASS";
  }

}

