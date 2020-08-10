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

vector<int> selectionSort(vector<int> array) {
  for (int i = 0; i < array.size(); ++i) {
    int min = i;
    for (int j = i; j < array.size(); ++j) {
      if (array[j] < array[min]) {
        min = j;
      }
    }
    if (min != i) swapp(&array[min], &array[i]);
  }
  return array;
}

int main(void) {
//    cout << "here";
//    vector<int> expected = {1, 2};
//    assert(bubbleSort({1, 2}) == expected);
  vector<int> g1(selectionSort({28, 3, 4}));

  for (auto i = g1.begin(); i != g1.end(); ++i)
    cout << *i << " ";

  cin.get();
  cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  return 0;
}

