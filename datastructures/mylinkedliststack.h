#ifndef MYLINKEDLISTSTACK_H
#define MYLINKEDLISTSTACK_H

#include <iostream>

class MyLinkedListStack {
private:
  struct Node {
    int data{};
    Node *next{NULL};
  };
  Node *head{NULL};

public:
  MyLinkedListStack() = default;

  bool isEmpty() const { return (head == NULL ? true : false); }
  int top() const;
  void printStack() const;
  void push(int data);
  void pop();
};

#endif // MYLINKEDLISTSTACK_H
