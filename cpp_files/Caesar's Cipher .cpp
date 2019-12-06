//
// Created by shivam on 12/6/19.
//


#include "iostream"
#include <bits/stdc++.h>

using namespace std;

string caesarCypherEncryptor(string str, int key) {
    // Write your code here.
    int i = 0;
    while (str[i] != '\0') {
        int val = key % 26;
        if ((int(str[i]) + val) < 123) {
            str[i] = char(int(str[i]) + val);
        } else {
            str[i] = char(int(str[i]) + val -26);
        }
        i++;
    }
    return str;
}



int main(void) {
    cout << "here";
    assert(caesarCypherEncryptor("abc", 3) == "def");
    cout <<"here";
    cin.get();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return 0;
}

