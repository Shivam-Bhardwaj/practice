//
// Created by shivam on 9/21/20.
//

#include "iostream"
#include "any"
#include "vector"
#include "cassert"
#include "algorithm"

using namespace std;

vector<int> smallestDifference(vector<int> arrayOne, vector<int> arrayTwo) {
  // Write your code here.
  sort(arrayOne.begin(), arrayOne.end());
  sort(arrayTwo.begin(), arrayTwo.end());
  vector<int> result{arrayOne.at(0), arrayTwo.at(0)};
  size_t ptr1{0}, ptr2{0};
  int current_min = abs(arrayOne.at(0)- arrayTwo.at(0));
  while(ptr1 < arrayOne.size() && ptr2 < arrayTwo.size()){
    int loop_min = abs(arrayOne.at(ptr1) - arrayTwo.at(ptr2));
    if(loop_min < current_min){
      result = {arrayOne.at(ptr1), arrayTwo.at(ptr2)};
      current_min = loop_min;
    } else{
      if(arrayOne.at(ptr1)< arrayTwo.at(ptr2)){
        ptr1++;
      } else{
        ptr2++;
      }
    }
  }
  return result;
}


int main() {
  vector<int> expected{28, 26};
  assert(smallestDifference({-1, 5, 10, 20, 28, 3},
                            {26, 134, 135, 15, 17}) == expected);
  cout << "hi";
}