//
// Created by shivam on 12/5/19.
//


#include "iostream"
#include <bits/stdc++.h>

using namespace std;

bool isPalindrome(string str) {
    // Write your code here.
//    bitset<128> B;
//    int i = 0;
//    while(str[i]!='\0'){
//        B.flip(int(str[i]));
//        i++;
//    }
//    if(B.count()>1) return false;
//    else return true;

    int n = str.size();
    int i =0;
    while(i<n/2){
        if(str[i]!=str[n-i-1]) return false;
        i++;
    }
    return true;
}


int main(void) {
    assert(isPalindrome("bab") == 1);
    cout<<"here";
    cin.get();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return 0;
}

