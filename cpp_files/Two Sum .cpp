//
// Created by shivam on 12/25/19.
//
#include "iostream"
#include <bits/stdc++.h>
#include "vector"

using namespace std;

vector<int> twoSum(vector<int> &nums, int target) {
    vector<int> result;
    unordered_map<int, int> m;
    for (int i = 0; i < nums.size(); ++i) {
        int pair = target - nums[i];
        auto itr = m.find(pair);
        if(itr!=m.end()){
            result.push_back(i);
            result.push_back(itr->second);
            sort(result.begin(),result.end());
            return result;
        }
        m[nums[i]] = i;
    }
    return result;

}

int main(void) {
    cout << "here\n\n";
//    vector<int> nums1 = {7,2,8,5,0,9,1,2,9,5,3,6,6,7,3,2,8,4,3,7,9,5,7,7,4,7,4,9,4,7,0,1,1,1,7,4,0,0,6};
    vector<int> nums1 = {3, 3};

    vector<int> v = twoSum(nums1, 6);

    for (int x : v)
        cout << x << " ";

    cout << "here";
    cin.get();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return 0;
}
