#ifndef MYDOUBLYLINKEDLIST_H
#define MYDOUBLYLINKEDLIST_H

#include <iostream>

class MyDoublyLinkedList {
public:
  struct Node {
    int data{};
    Node *prev{NULL};
    Node *next{NULL};
  };

  Node *head{NULL};

  MyDoublyLinkedList() = default;

  bool isEmpty() const { return (head == NULL ? true : false); };
  void printList() const;
  void addNode(int data, int position);
  void deleteNode(int position);
  void reverse();
};

#endif // MYDOUBLYLINKEDLIST_H
