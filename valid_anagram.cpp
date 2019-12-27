#include "iostream"
#include <bits/stdc++.h>
#include "vector"

using namespace std;

bool isAnagram(string s, string t) {

}


int main() {
//    cout << "here";


    assert(isAnagram("anagram", "nagaram") == true);
    assert(isAnagram("rat", "car") == true);

    cout << "success";
    cin.get();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return 0;
}