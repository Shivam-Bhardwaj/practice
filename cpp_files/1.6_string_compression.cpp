#include <bits/stdc++.h>
#include "string"
#include "map"

using namespace std;

char *encode(char *src);

int main() {

    int T;
    cin >> T;
    while (T--) {
        char str[10000];
        cin >> str;

        cout << encode(str) << endl;+

        +

        +
    }
    return 0;
}

/*This is a function problem.You only need to complete the function given below*/
/*You are required to complete this function */
char *encode(char *src) {
    //Your code here
    int n = strlen(src);
    map<char, int> freq;
    int count = 0;
    for (int i = 0; i < n; ++i) {
        if (src[i] == src[i + 1]) {
            freq.insert({src[i], ++count});
        }
        count = 0;
    }
    return src;
}     
 