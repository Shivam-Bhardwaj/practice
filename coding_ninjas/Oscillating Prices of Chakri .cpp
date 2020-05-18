//
// Created by shivam on 5/15/20.
//

#include<iostream>

using namespace std;

void profit(int arr[], int n) {
  int minindex = 0;
  int maxprofit = 0;
  int i = 1;
  while (i < n) {
    if (arr[i] < arr[minindex]) {
      minindex = i;
    }
    int cp = arr[i] - arr[minindex];
    if (cp > maxprofit) {
      maxprofit = cp;
    }
    i++;
  }
  cout << maxprofit;
}

int main() {
  int n;
  cin >> n;
  int *arr = new int[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  profit(arr, n);
}

//#include "iostream"
//#include <bits/stdc++.h>
//#include "vector"
//
//using namespace std;
//
//
//int main() {
////    cout << "here";
//  int n;
//  cin >> n;
//  int *arr = new int[n];
//  for (int j = 0; j < n; ++j) {
//    cin >> arr[j];
//  }
//  int profit{0};
//  for (int i = 0; i < n; ++i) {
//    for (int j = i+1; j < n; ++j) {
//      if(arr[j] - arr[i] > profit){
//        profit = arr[j] - arr[i];
//      }
//    }
//  }
//  printf("%d", profit);
//  delete[] arr;
//  cout << "success";
//  cin.get();
//  cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//  return 0;
//}


