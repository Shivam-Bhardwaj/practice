//
// Created by shivam on 12/5/19.
//


#include "iostream"
#include <bits/stdc++.h>

using namespace std;

vector<int> findThreeLargestNumbers(vector<int> array) {
    // Write your code here.
    vector<int> result(array.begin(), array.begin() + 3);
    sort(result.begin(), result.end());
    for (int i = 3; i < array.size(); ++i) {
        if(array[i]>result[0]) {
            result[0]=array[i];
            sort(result.begin(), result.end());
        }

    }
    return result;
}


int main(void) {

    cout << "here";
    vector<int> expected{11, 43, 55};
    assert(findThreeLargestNumbers({55, 43, 11, 3, -3, 10}) == expected);

//    for (int i = 0; i < findThreeLargestNumbers({55, 43, 11, 3, -3, 10}).size(); ++i) {
//        cout << findThreeLargestNumbers({55, 43, 11, 3, -3, 10})[i] << " ";
//    }
    cin.get();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return 0;
}

