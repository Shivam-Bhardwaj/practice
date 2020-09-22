//
// Created by shivam on 9/21/20.
//

#include "iostream"
#include "any"
#include "vector"
#include "cassert"

using namespace std;

vector<int> insertionSort(vector<int> array) {
  // Write your code here.
  for (int i = 0; i < array.size() - 1; ++i) {
    for (int j = i+1; j >0 ; j--) {
      if (array.at(j)<array.at(j-1)){
        swap(array.at(j), array.at(j-1));
      }
    }
  }
  return array;
}


int main() {
  vector<int> expected = {2, 3, 5, 5, 6, 8, 9};

  assert(insertionSort({8, 5, 2, 9, 5, 6, 3}) == expected);
}