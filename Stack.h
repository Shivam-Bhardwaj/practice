//
// Created by shivam on 11/7/19.
//

#ifndef CPP_PRACTICE_STACK_H
#define CPP_PRACTICE_STACK_H

template <class T>
class Stack {
private:
    T* st;
    int size;
    int top;
public:
    Stack(){
        size = 5;
        top = -1;
        st  = new T[size];
    }
    Stack(int x){
        size = x;
        top = -1;
        st = new T[size];
    }

};


#endif //CPP_PRACTICE_STACK_H
