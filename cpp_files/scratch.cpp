//
// Created by shivam on 9/21/20.
//

#include "iostream"
#include "any"
#include "vector"
#include "cassert"
#include "algorithm"

using namespace std;
void swapp(int &a, int &b){
  int temp = a;
  a = b;
  b = temp;
}

vector<int> selectionSort(vector<int> array) {
  // Write your code here.
  int j = 0;
  for (int i = 0; i < array.size(); ++i) {
    int min_pose = i;
    for (j = i; j < array.size(); ++j) {
      if (array.at(j) < array.at(min_pose)){
        min_pose = j;
      }
    }
    swap(array[i], array[min_pose]);
  }
  return array;
}


int main() {
  vector<int> expected = {2, 3, 5, 5, 6, 8, 9};
  assert(selectionSort({8, 5, 2, 9, 5, 6, 3}) == expected);
}