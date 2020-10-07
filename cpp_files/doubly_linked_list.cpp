//
// Created by shivam on 10/7/20.
//
//
// Created by shivam on 9/21/20.
//

#include "vector"
#include "cassert"

using namespace std;
using namespace std;

class Node {
public:
  int value;
  Node *prev;
  Node *next;

  Node(int value);
};

// Feel free to add new properties and methods to the class.
class DoublyLinkedList {
public:
  Node *head;
  Node *tail;

  DoublyLinkedList() {
    head = NULL;
    tail = NULL;
  }

  void setHead(Node *node) {
    // Write your code here.
    if (head == NULL) {
      head = node;
      tail = node;
      return;
    }
    insertBefore(head, node);
  }

  void setTail(Node *node) {
    // Write your code here.
    if (tail == NULL) {
      setHead(node);
      return;
    }
    insertAfter(tail, node);
  }

  void insertBefore(Node *node, Node *nodeToInsert) {
    // Write your code here.
    if (nodeToInsert == head && nodeToInsert == tail) {
      return;
    }
    remove(nodeToInsert);
    nodeToInsert->next = node;
    nodeToInsert->prev = node->prev;
    if (node->prev == NULL) {
      head = nodeToInsert;
    } else {
      node->prev->next = nodeToInsert;
    }
    node->prev = nodeToInsert;

  }

  void insertAfter(Node *node, Node *nodeToInsert) {
    // Write your code here.
    if (nodeToInsert == head && nodeToInsert == tail) {
      return;
    }
    remove(nodeToInsert);
    nodeToInsert->next = node->next;
    nodeToInsert->prev = node;
    if (node->next == NULL) {
      tail = nodeToInsert;
    } else {
      node->next->prev = nodeToInsert;
    }
    node->next = nodeToInsert;
  }

  void insertAtPosition(int position, Node *nodeToInsert) {
    // Write your code here.
//    if (head == NULL && tail == NULL) {
//      remove(nodeToInsert);
//      return;
//    }
    if (position == 1) {
      setHead(nodeToInsert);
      return;
    }
    int current_position = 1;
    Node *current_node = head; // TODO
    while (current_node != NULL && current_position++ != position) {
      current_node = current_node->next;
    }
    if (current_node == NULL) {
      setTail(nodeToInsert);
    } else {
      insertBefore(current_node, nodeToInsert);
    }
  }

  void removeNodesWithValue(int value) {
    // Write your code here.
    Node *node = head; //TODO
    while (node != NULL) {
      Node *node_to_remove = node;
      node = node->next;
      if (node_to_remove->value == value) {
        remove(node_to_remove);
      }
    }
  }

  void remove(Node *node) {
    // Write your code here.
    if (node == head) {
      head = head->next;
    }
    if (node == tail) {
      tail = tail->prev;
    }
    if (node->prev != NULL)
      node->prev->next = node->next;

    if (node->next != NULL)
      node->next->prev = node->prev;

    node->next = NULL;
    node->prev = NULL;

  }

  bool containsNodeWithValue(int value) {
    // Write your code here.
    Node *current_node = head;
    // TODO
    while (current_node != NULL) {
      if (current_node->value == value) return true;
      current_node = current_node->next;
    }
    return false;
  }
};

Node::Node(int value) {
  this->value = value;
  prev = NULL;
  next = NULL;
};

vector<int> getNodeValuesHeadToTail(DoublyLinkedList linkedList) {
  vector<int> values = {};
  Node *node = linkedList.head;
  while (node != NULL) {
    values.push_back(node->value);
    node = node->next;
  }
  return values;
}

vector<int> getNodeValuesTailToHead(DoublyLinkedList linkedList) {
  vector<int> values = {};
  Node *node = linkedList.tail;
  while (node != NULL) {
    values.push_back(node->value);
    node = node->prev;
  }
  return values;
}

void bindNodes(Node *nodeOne, Node *nodeTwo) {
  nodeOne->next = nodeTwo;
  nodeTwo->prev = nodeOne;
}

int main() {
  {
    DoublyLinkedList linkedList;
    Node one(1);
    Node two(2);
    Node three(3);
    Node three2(3);
    Node three3(3);
    Node four(4);
    Node five(5);
    Node six(6);
    bindNodes(&one, &two);
    bindNodes(&two, &three);
    bindNodes(&three, &four);
    bindNodes(&four, &five);
    linkedList.head = &one;
    linkedList.tail = &five;

    linkedList.setHead(&four);
    assert(getNodeValuesHeadToTail(linkedList) ==
           (vector<int>{4, 1, 2, 3, 5}));
    assert(getNodeValuesTailToHead(linkedList) ==
           (vector<int>{5, 3, 2, 1, 4}));

    linkedList.setTail(&six);
    assert(getNodeValuesHeadToTail(linkedList) ==
           (vector<int>{4, 1, 2, 3, 5, 6}));
    assert(getNodeValuesTailToHead(linkedList) ==
           (vector<int>{6, 5, 3, 2, 1, 4}));

    linkedList.insertBefore(&six, &three);
    assert(getNodeValuesHeadToTail(linkedList) ==
           (vector<int>{4, 1, 2, 5, 3, 6}));
    assert(getNodeValuesTailToHead(linkedList) ==
           (vector<int>{6, 3, 5, 2, 1, 4}));

    linkedList.insertAfter(&six, &three2);
    assert(getNodeValuesHeadToTail(linkedList) ==
           (vector<int>{4, 1, 2, 5, 3, 6, 3}));
    assert(getNodeValuesTailToHead(linkedList) ==
           (vector<int>{3, 6, 3, 5, 2, 1, 4}));

    linkedList.insertAtPosition(1, &three3);
    assert(getNodeValuesHeadToTail(linkedList) ==
           (vector<int>{3, 4, 1, 2, 5, 3, 6, 3}));
    assert(getNodeValuesTailToHead(linkedList) ==
           (vector<int>{3, 6, 3, 5, 2, 1, 4, 3}));

    linkedList.removeNodesWithValue(3);
    assert(getNodeValuesHeadToTail(linkedList) ==
           (vector<int>{4, 1, 2, 5, 6}));
    assert(getNodeValuesTailToHead(linkedList) ==
           (vector<int>{6, 5, 2, 1, 4}));

    linkedList.remove(&two);
    assert(getNodeValuesHeadToTail(linkedList) == (vector<int>{4, 1, 5, 6}));
    assert(getNodeValuesTailToHead(linkedList) == (vector<int>{6, 5, 1, 4}));

    assert(linkedList.containsNodeWithValue(5) == true);
  }

}


