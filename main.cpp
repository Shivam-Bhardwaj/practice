#include "iostream"
#include "Stack.h"
#include "Stack.cpp"
using namespace std;


int main(){
    Stack<char> S(3);
    S.Display();
    S.push('a');
    S.push('b');

    cout <<"display after adding a and b \n";
    S.Display();
    S.push('c');
    S.push('d');

    cout <<"\ndisplay after adding c and d \n";
    S.Display();

    cout<<"\ndisplay after popping \n";
    S.pop();
    S.Display();

    return 0;
}