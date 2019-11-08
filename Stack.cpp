//
// Created by shivam on 11/7/19.
//

#include "Stack.h"
#include "iostream"
using namespace std;
template <class T>
void Stack<T>::Display() {
    if(top == -1) { cout<<"empty stack\n"; return;}

    int temp = top;
    while(temp>-1){
//        temp--;
        cout<<st[temp--]<<" ";
    }
    return;
}

template <class T>
void Stack<T>::push(T x) {
    if(top == size-1) {
        cout <<"\nStack full can't add "<< x<<endl;
        return;
    }

    st[++top] = x;
}

template <class T>
void Stack<T>::pop() {
    cout << "removing " << st[top--]<<endl;
}