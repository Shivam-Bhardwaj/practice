//
// Created by shivam on 9/30/20.
//

#include "iostream"
#include "any"
#include "vector"
#include "cassert"
#include "algorithm"
#include "map"

using namespace std;

vector<vector<int>> powerset(vector<int> array) {
  // Write your code here.
  vector<vector<int>> result = {{}};
  for (const auto i: array) {
    auto number_of_elements_in_subset = result.size();
    for (auto j = 0; j < number_of_elements_in_subset; j++) {
      vector<int> current_subset = result.at(j);
      current_subset.push_back(i);
      result.push_back(current_subset);
    }
  }
  return result;
}

int main() {
  // TEST1
  {
    vector<vector<int>> output = powerset({1, 2, 3});
    for (int i = 0; i < output.size(); i++) {
      sort(output[i].begin(), output[i].end());
    }
    assert(output.size() == 8);
    vector<vector<int>>::iterator it =
      find(output.begin(), output.end(), vector<int>{});
    assert(it != output.end());
    it = find(output.begin(), output.end(), vector<int>{1});
    assert(it != output.end());
    it = find(output.begin(), output.end(), vector<int>{2});
    assert(it != output.end());
    it = find(output.begin(), output.end(), vector<int>{3});
    assert(it != output.end());
    it = find(output.begin(), output.end(), vector<int>{1, 2});
    assert(it != output.end());
    it = find(output.begin(), output.end(), vector<int>{1, 3});
    assert(it != output.end());
    it = find(output.begin(), output.end(), vector<int>{2, 3});
    assert(it != output.end());
    it = find(output.begin(), output.end(), vector<int>{1, 2, 3});
    assert(it != output.end());
    cout << "TEST 1 PASS";
  }
}

