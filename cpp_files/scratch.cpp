//
// Created by shivam on 9/21/20.
//

#include "iostream"
#include "any"
#include "vector"
#include "cassert"

using namespace std;

vector<int> bubbleSort(vector<int> array) {
  // Write your code here.Second Pass:
  bool swap_flag = false;
  for (int i = 0; i < array.size(); ++i) {
    for (int j = 0; j < array.size()-1; ++j) {
      if (array.at(j)>array.at(j+1)){
        swap_flag= true;
        swap(array[j],array[j+1]);
      }
    }
    if (!swap_flag) return array;
  }
  return array;
}


int main() {
  vector<int> expected = {2, 3, 5, 5, 6, 8, 9};

  assert(bubbleSort({8, 5, 2, 9, 5, 6, 3}) == expected);
}