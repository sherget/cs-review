// Copyright (c) 2022 Somebody. All rights reserved.

#include "mylinkedlist.h"
#include "mydoublylinkedlist.h"
#include "myarraystack.h"
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

void doublyLinkedListDriver() {
  MyDoublyLinkedList dll;

  dll.printList();
  dll.addNode(2,1);
  dll.addNode(4,1);
  dll.addNode(8,1);
  dll.addNode(5,2);
  dll.addNode(10,4);
  dll.addNode(999,999);
  dll.printList();

  std::cout << '\n';
  dll.printList();
  dll.deleteNode(1);
  dll.printList();
  dll.deleteNode(4);
  dll.deleteNode(999);
  dll.printList();
  dll.reverse();
  dll.printList();
}

void arrayStackDriver() {
  MyArrayStack s;
  s.printStack(); // Error empty list
  s.pop(); // Error can't pop from empty list
  s.push(2);
  s.push(4);
  s.push(8);
  s.push(16);
  s.push(32);
  s.push(64);
  s.push(128);
  s.push(256);
  s.push(512);
  s.push(1024);
  s.printStack();
  std::cout << s.top() << std::endl;
  s.pop();
  std::cout << s.top() << std::endl;
  s.push(1024);
  s.push(2048);
  s.push(4096); // overflow -> array gets copied over to a larger array
}

int main() {
  // linkedListDriver();
  // doublyLinkedListDriver();
  arrayStackDriver();

  return 0;
}
