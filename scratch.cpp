//
// Created by shivam on 9/21/20.
//

#include "iostream"
#include "vector"
#include "cassert"
#include "algorithm"
#include "unordered_map"

using namespace std;

class Node{
  Node* next;
  int element;
};

class List {

public:
  explicit List(int start_element){
    next = nullptr;
    element = start_element;
  }
  void add_element(int element);
  void delete_element(int element);
  void show_elements();
};

void List::add_element(int element) {
  if (this->next == nullptr){

  }
}

int main() {
  {
    List my_list(0);
    my_list.add_element(1);
    my_list.add_element(2);
    my_list.add_element(3);

    my_list.show_elements();

    my_list.delete_element(2);
    my_list.show_elements();
    my_list.add_element(4);
    my_list.add_element(4);
    my_list.show_elements();

    my_list.delete_element(4);
    my_list.show_elements();
    cout << "TEST 0 PASS";
  }
}

