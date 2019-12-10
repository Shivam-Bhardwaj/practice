//
// Created by shivam on 12/6/19.
//


#include "iostream"
#include <bits/stdc++.h>

using namespace std;
using namespace std;

class Node {
public:
    int data;
    Node *next;
};

Node *head = nullptr;

void insert(int pos, int data);

void push(int data) {
    Node *temp = new Node;
    if (head == nullptr) {
        head = temp;
        temp->data = data;
        temp->next = nullptr;
        return;
    }
    Node *curr = head;
    while (curr != nullptr) {
        curr = curr->next;
    }

}

void pop();

void del(int data);

void display(string s);


int main(void) {
    cout << "here";
    push(2);
    push(3);
    push(1);
    display("after inserting 2, 3, 1 \n");
    insert(2, 10);
    display("after inserting 10 at pos = 2");
    pop();
    display("after popping");
    del(3);
    display("after deleting at pos = 2");
    cin.get();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return 0;
}

