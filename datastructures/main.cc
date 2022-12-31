// Copyright (c) 2022 Somebody. All rights reserved.

#include "mylinkedlist.h"
#include <iostream>

void linkedListDriver() {
  MyLinkedList ll;

  std::cout << "Create linked list:" << std::endl;
  ll.printList();
  ll.addNode(4, 1);
  ll.addNode(6, 1);
  ll.addNode(8, 1);
  ll.addNode(13, 2);
  ll.addNode(37, 3);
  ll.addNode(100, 6);
  ll.addNode(99, 99); // Error out of range
  ll.printList();

  std::cout << '\n';
  ll.printList();
  ll.deleteNode(3);
  ll.printList();
  ll.deleteNode(1);
  ll.printList();
  ll.deleteNode(1);
  ll.deleteNode(20); // Error out of range
  ll.printList();

  std::cout << '\n';
  ll.printList();
  ll.reverse();
  ll.printList();
  ll.reverseRecursive(ll.head);
  ll.printList();
}

int main() {
  linkedListDriver();

  return 0;
}
