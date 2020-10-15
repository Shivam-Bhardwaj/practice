//
// Created by shivam on 12/25/19.
//

#include "iostream"
#include <bits/stdc++.h>
#include "vector"

using namespace std;


vector<int> intersect(vector<int> &nums1, vector<int> &nums2) {
  vector<int> result;
  unordered_map<int, int> n1;
  unordered_map<int, int> n2;
  unordered_map<int, int>::iterator itr1;
  for (auto i : nums1) {
    n1[i]++;
  }

  for (auto i : nums2) {
    n2[i]++;
  }

  for (itr1 = n1.begin(); itr1 != n1.end(); itr1++) {
    if (n2.find(itr1->first) != n2.end()) {
      int x = itr1->first;
      for (int i = 0; i < min((n1.find(x)->second), (n2.find(x)->second)); i++) {
        result.push_back(x);
      }
    }
  }
  return result;

}


int main(void) {
  cout << "here\n\n";
  vector<int> nums1 = {2, 2, 3};
  vector<int> nums2 = {1, 2, 2, 5, 3};

  vector<int> v = intersect(nums1, nums2);
  for (int x : v)
    cout << x << " ";

  cout << "here";
  cin.get();
  cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  return 0;
}