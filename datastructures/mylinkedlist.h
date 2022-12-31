// Copyright (c) 2022 Somebody. All rights reserved.
#ifndef MY_LINKED_LIST_H
#define MY_LINKED_LIST_H

#include <iostream>

class MyLinkedList {
public:
  struct Node {
    int data{};
    Node *next{NULL};
  };

  Node *head{NULL};

  MyLinkedList() = default;
  bool isEmpty() { return (head == NULL ? true : false); }
  void addNode(int data, int position);
  void deleteNode(int position);
  void printList();
  void reverse();
  void reverseRecursive(Node *prev);
};

#endif // MY_LINKED_LIST_H
