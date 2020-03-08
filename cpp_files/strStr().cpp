//
// Created by shivam on 12/29/19.
//

#include "iostream"
#include <bits/stdc++.h>
#include "vector"

using namespace std;

int strStr(string haystack, string needle) {
    int h  =haystack.size();
    int n = needle.size();
    if(n==0) return 0;
    if(n>h) return -1;
    int i, j, ctr;

}

int main() {
//    cout << "here";

    assert(strStr("abc", "b") == 1);
    assert(strStr("abcd", "bc") == 1);
    assert(strStr("", "") == 0);
    assert(strStr("", "a") == -1);
    assert(strStr("a", "") == 0);
    assert(strStr("abc", "h") == -1);
    assert(strStr("abvc", "vc") == 2);



    cout << "success";
    cin.get();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return 0;
}