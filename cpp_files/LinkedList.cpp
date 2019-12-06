//
// Created by shivam on 11/30/19.
//


#include "iostream"
#include <bits/stdc++.h>

using namespace std;


class Node{
public:
    Node * next;
    int data;
};

void printlist(Node * head){
    while (head!= nullptr){
        cout << head->data;
        head = head->next;
    }
}

void push(Node* head, int val){

}

int main(void) {
    cout << "here";
//    Node* head = nullptr;
//    Node* a = nullptr;
//    Node* b = nullptr;
//
//    head = new Node;
//    a = new Node;
//    b = new Node;
//
//    head->next = a;
//    a->next =b;
//
//    head->data = 1;
//    a->data = 2;
//    b->data = 3;
//
//    cout << a->data;
//    printlist(head);
//    cin.get();
//    cout << sizeof(int);
//    cout<< sizeof(head->next);

    Node *head = new Node;
    head->next = nullptr;
    head->data = 1;

    


    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return 0;
}

