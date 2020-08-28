//
// Created by shivam on 8/14/2020.
//

#include "iostream"
#include <bits/stdc++.h>
#include "vector"
#include <iostream>
#include <iterator>
#include <fstream>
#include <vector>
#include <algorithm> // for std::copy

//using vector<int> = std::vector<int>;
using namespace std;

long merge(vector<int> &array, int left, int mid, int right) {
  vector<int> temp_l;
  vector<int> temp_r;
  int left_size = mid - left + 1;
  int right_size = right - mid;
  long inv_ = 0;
  for (int i = 0; i < left_size; ++i) {
    temp_l.push_back(array[i + left]);
  }
  for (int i = 0; i < right_size; ++i) {
    temp_r.push_back(array[i + mid + 1]);
  }
  int i{0}, j{0}, k{left};

  while (i < left_size && j < right_size) {
    if (temp_l.at(i) < temp_r.at(j)) {
      array[k] = temp_l.at(i);
      i++;
      k++;
    } else {
      array[k] = temp_r.at(j);
      inv_ += mid - i;
      j++;
      k++;
    }
  }
  while (i < left_size) {
    array[k] = temp_l.at(i);
    i++;
    k++;
    inv_++;
  }

  while (j < right_size) {
    array[k] = temp_r.at(j);
    j++;
    k++;
  }
  return inv_;
}

long sort(vector<int> &array, int left, int right) {
  //base case
  long inv = 0;
  if (left < right) {
    // recursive call
    int mid = left + (right - left) / 2;
    inv = sort(array, left, mid);
    inv += sort(array, mid + 1, right);

    // merge
    inv+= merge(array, left, mid, right);
  }
  return inv;
}

bool check(vector<int> &a) {
  for (int i = 0; i < a.size() - 1; ++i) {
    if (a.at(i) > a.at(i + 1)) {
      return false;
    }
  }
  return true;
}

int main() {
//  vector<int> array{6, 5, 4, 3, 2, 1};
//  vector<int> array{1, 20, 6, 4, 5};
//  vector<int> array{2, 4, 1, 3, 5};
  std::ifstream is("file2.txt");
  std::istream_iterator<int> start(is), end;
  std::vector<int> array(start, end);
  long inv = sort(array, 0, array.size() - 1);
//  for (int i : array) {
//    std::cout << i << " ";
//  }
  std::cout << std::endl << inv;
  if (check(array)) {
    std::cout << "\nsuccess";
  } else {
    std::cout << "\nfail";
  }
}

