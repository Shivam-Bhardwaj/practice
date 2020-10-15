//
// Created by shivam on 12/5/19.
//


#include "iostream"
#include <bits/stdc++.h>

using namespace std;

void swapp(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
  return;
}

vector<int> insertionSort(vector<int> array) {
  for (int i = 1; i < array.size(); ++i) {
    int j = i;
    while (j > 0 && array[j] < array[j - 1]) {
      swapp(&array[j], &array[j - 1]);
      j--;
    }
  }
  return array;
}

int main(void) {
//    cout << "here";
//    vector<int> expected = {1, 2};
//    assert(bubbleSort({1, 2}) == expected);
  vector<int> g1(insertionSort({28, 3, 4}));

  for (auto i = g1.begin(); i != g1.end(); ++i)
    cout << *i << " ";

  cin.get();
  cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  return 0;
}

