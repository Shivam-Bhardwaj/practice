//
// Created by shivam on 9/21/20.
//

#include "iostream"
#include "any"
#include "vector"
#include "cassert"
#include "algorithm"
#include "map"
#include "stack"

using namespace std;


class LinkedList {
public:
  int value;
  LinkedList *next;

  LinkedList(int value);

  void addMany(vector<int> values);

  vector<int> getNodesInArray();
};

void create_stack(stack<LinkedList *> &list_stack, LinkedList *head) {
  while (head != NULL) {
    list_stack.push(head);
    head = head->next;
  }
}

void pop_stack(stack<LinkedList *> &list_stack, int k) {
  for (int i = 0; i < k -1; ++i) {
    list_stack.pop();
  }
}


void removeKthNodeFromEnd(LinkedList *head, int k) {
  // Write your code here.
  LinkedList * start= head;
  LinkedList * end=head;
  while(end && k--){
    end = end->next;
  }
  while (end)
  {
    start = start->next;
    end = end->next;
  }

  if(!end){
    auto next = start->next;
//    list_stack.pop();
    start = start->next;
  }

}

class TestLinkedList : public LinkedList {
public:
  TestLinkedList(int value);

  void addMany(vector<int> values);

  vector<int> getNodesInArray();
};

LinkedList::LinkedList(int value) {
  this->value = value;
  this->next = NULL;
}

TestLinkedList::TestLinkedList(int value) : LinkedList(value) {
  this->value = value;
  this->next = NULL;
}

void TestLinkedList::addMany(vector<int> values) {
  LinkedList *current = this;
  while (current->next != NULL) {
    current = current->next;
  }
  for (int value : values) {
    current->next = new LinkedList(value);
    current = current->next;
  }
}

vector<int> TestLinkedList::getNodesInArray() {
  vector<int> nodes{};
  LinkedList *current = this;
  while (current != NULL) {
    nodes.push_back(current->value);
    current = current->next;
  }
  return nodes;
}

int main() {
  {
    TestLinkedList test(0);
    test.addMany({1, 2, 3, 4, 5, 6, 7, 8, 9});
    TestLinkedList expected(1);
    expected.addMany({2, 3, 4, 5, 6, 7, 8, 9});
    removeKthNodeFromEnd(&test, 10);
    assert(test.getNodesInArray() == expected.getNodesInArray());
    cout << "TEST 0 PASS";
  }

}

