//
// Created by shivam on 9/28/20.
//

#include "iostream"
#include "any"
#include "vector"
#include "cassert"
#include "algorithm"
#include "map"

using namespace std;


void helper(int i, vector<int> &array, vector<vector<int>> &permutation) {
  if (i == array.size() - 1) {
    permutation.push_back(array);
  } else {
    for (int j = i; j < array.size(); ++j) {
      swap(array.at(i), array.at(j));
      helper(i+1, array, permutation);
      swap(array.at(j), array.at(i));
    }
  }
}

vector<vector<int>> getPermutations(vector<int> array) {
  // Write your code here.
  vector<vector<int>> result;
  helper(0, array, result);
  return result;
}

bool contains(vector<vector<int>> array1, vector<int> array2) {
  for (vector<int> subArray : array1) {
    if (array2 == subArray) {
      return true;
    }
  }
  return false;
}

int main() {
  // TEST1
  {

    vector<vector<int>> perms = getPermutations({1, 2, 3});
    assert(perms.size() == 6);
    assert(contains(perms, {1, 2, 3}));
    assert(contains(perms, {1, 3, 2}));
    assert(contains(perms, {2, 1, 3}));
    assert(contains(perms, {2, 3, 1}));
    assert(contains(perms, {3, 1, 2}));
    assert(contains(perms, {3, 2, 1}));
  }
}