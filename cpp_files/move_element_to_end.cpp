//
// Created by shivam on 9/21/20.
//

#include "iostream"
#include "any"
#include "vector"
#include "cassert"
#include "algorithm"

using namespace std;

vector<int> moveElementToEnd(vector<int> array, int toMove) {
  // Write your code here.
  if (array.empty()) return array;
  size_t to_move_ptr{0}, array_ptr{array.size() - 1};
  while (to_move_ptr < array_ptr) {
    while (array.at(to_move_ptr) != toMove && (to_move_ptr < array_ptr)) {
      to_move_ptr++;
    }
    while (array.at(array_ptr) == toMove) {
      array_ptr--;
    }
    swap(array.at(to_move_ptr), array.at(array_ptr));
  }
  return array;
}


int main() {
  vector<int> array = {1,2,3,4};
  int toMove = 3;
  vector<int> expectedStart = {1,2,3,4};
  vector<int> expectedEnd = {};
  vector<int> output = moveElementToEnd(array, toMove);
  assert(output.size() == array.size());
  vector<int> outputStart = vector<int>(output.begin(), output.begin() +4);
  sort(outputStart.begin(), outputStart.end());
  vector<int> outputEnd = vector<int>(output.begin() +4, output.end());
  assert(outputStart == expectedStart);
  assert(outputEnd == expectedEnd);
  cout << "hi";
}