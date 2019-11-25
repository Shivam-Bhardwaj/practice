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

        cout << encode(str) << endl;
    }
    cin.get();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return 0;
}

/*This is a function problem.You only need to complete the function given below*/
/*You are required to complete this function */
char *encode(char *src) {
    //Your code here
    int i, ctr, j;
    i = ctr = j = 0;
    ctr =1;
    char cc=src[0];    // current character
    while(src[i]!=0){

        cc = src [i];
        while (src[i+1]==cc){
            ctr++;
            i++;
        }
        if(ctr==0){

        }
        else if(ctr == 1){
            ctr = 1;
            src[j] = cc;
            j++;

        }
        else if(ctr>1){

            src[j] = cc;
            src[j+1] = char(ctr+'0');
            ctr = 1;
            j+=2;
        }
    i++;
    }

    src[j] = 0;

    return src;
}     
 