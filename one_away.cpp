//
// Created by shivam on 11/23/19.
//

#include "iostream"
#include "cstdlib"
#include "string"

using namespace std;
bool one_add(string s1, string s2);
bool one_replace(string s1, string s2);


bool one_away(string s1, string s2){
    int x = s1.length()-s2.length();
    if(abs(x<=1)){
        if(x==0)
            return one_replace(s1, s2);
        else
            return one_add(s1, s2);
    }
    return false;

}

bool one_add(string s1, string s2){

    return false;
}

bool one_replace(string s1, string s2){
    bool flag = false;
    for (int i = 0; i < s1.length(); ++i) {
        if((flag == false)&&(s1[i]!=s2[i])){
            flag = true;
        }else{
            if((flag == true)&&(s1[i]!=s2[i])) return false;
        }
    }
    return true;
}

int main(){
    string s1 = "aaa";
    string s2 = "aba";
    cout<<one_away(s1,s2);
}