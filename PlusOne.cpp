//
// Created by shivam on 12/25/19.
//
#include "iostream"
#include <bits/stdc++.h>
#include "vector"

using namespace std;

vector<int> PlusOne(vector<int>& digits) {
    vector<int> result;
    reverse(digits.begin(), digits.begin());
    int carry = 0;
}

int main(void) {
    cout << "here\n\n";
    vector<int> nums1 = {7,2,8,5,0,9,1,2,9,5,3,6,6,7,3,2,8,4,3,7,9,5,7,7,4,7,4,9,4,7,0,1,1,1,7,4,0,0,6};

    vector<int> v = PlusOne(nums1);
    /*
    for (int x : v)
        cout << x << " ";
*/
    cout << "here";
    cin.get();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return 0;
}
