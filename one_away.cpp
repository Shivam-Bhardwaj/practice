//
// Created by shivam on 11/23/19.
//

#include "iostream"
#include "cstdlib"
#include "string"

using namespace std;

bool one_add(string s1, string s2);
bool one_remove(string s1, string s2);
bool one_replace(string s1, string s2);


bool one_away(string s1, string s2) {
    int x = s1.length() - s2.length();
    if (x == 0) {
        return one_replace(s1, s2);
    } else if (x == 1) {
        return one_remove(s1, s2);
    } else if (x == -1) {
        return one_add(s1, s2);
    } else {
        return false;
    }
}

bool one_add(string s1, string s2) {
    bool flag = false;
    for (int i = 0, j =0; i < s1.length(); ++i, ++j) {
        if ((flag == false) && (s1[i] != s2[j])) {
            flag = true; ++i;
        } else {
            if ((flag == true) && (s1[i] != s2[i])) return false;
        }
    }
    return true;

}

bool one_remove(string s1, string s2) {
    bool flag = false;
    for (int i = 0, j =0; i < s2.length(); ++i, ++j) {
        if ((flag == false) && (s1[i] != s2[j])) {
            flag = true; ++i;
        } else {
            if ((flag == true) && (s1[i] != s2[i])) return false;
        }
    }
    return true;

}

bool one_replace(string s1, string s2) {
    bool flag = false;
    for (int i = 0; i < s1.length(); ++i) {
        if ((flag == false) && (s1[i] != s2[i])) {
            flag = true;
        } else {
            if ((flag == true) && (s1[i] != s2[i])) return false;
        }
    }
    return true;
}

int main() {
    string s1 = "23";
    string s2 = "32";
    cout << one_away(s1, s2);
}