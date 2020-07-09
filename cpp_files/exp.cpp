//
// Created by shivam on 12/6/19.
//


#include "iostream"
#include <bits/stdc++.h>
#include "vector"

using namespace std;

void reverse(vector<int>& nums, int start, int end) {
   while (end>start){
       swap(nums[start],nums[end]);
       start++; end--;
   }
}

void removeDuplicates(vector<int>& nums, int k){
    k = k % nums.size();
    reverse(nums, 0, nums.size()-1);
    reverse(nums, 0, k-1);
    reverse(nums, k, nums.size()-1);
}

int main(void) {
    cout << "here\n\n";
    assert(removeDuplicates{[0,0,0,0,1,1,1,2,2,2,3,4,4,4}, 14) == {0,1,2,3,4});
    vector<int> v{-2};
    removeDuplicates(v, 3);

    for (int x : v)
        cout << x << " ";

    cout <<"here";
    cin.get();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return 0;
}

