//
// Created by shivam on 12/29/19.
//

#include "iostream"
#include <bits/stdc++.h>
#include "vector"

using namespace std;

int myAtoi(string str) {
    bool neg = false;
    bool start = true;
    vector<int> v;
    for (int i = 0; i < str.size(); ++i) {
        if(str[i]==' ') continue;
        if(str[i]=='-') {
            neg = true;
            continue;
        }
        if(isdigit(str[i]){
            start = true;
            if
        }
    }
}


int main() {
//    cout << "here";


    assert(myAtoi("42") == 42);
    assert(myAtoi("   -42") == -42);
    assert(myAtoi("4193 with words") == 4193);
    assert(myAtoi("words and 987") == 0);
    assert(myAtoi("-91283472332") == -2147483648);


    cout << "success";
    cin.get();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return 0;
}