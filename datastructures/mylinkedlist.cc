#include "mylinkedlist.h"

void MyLinkedList::addNode(int data, int position) {
  int index{1};

  // Add initial node
  if (isEmpty()) {
    head = new Node{data, NULL};
    return;
  }

  // Handle edge case: insert at head
  if (position == index) {
    Node *tmp = new Node{data, head};
    head = tmp;
    return;
  }

  // Regular inserts at nth position
  Node *current = head;
  while (current != NULL) {
    if (index == position - 1) {
      Node *tmp = new Node{data, current->next};
      current->next = tmp;
      return;
    }
    index++;
    current = current->next;
  }

  std::cout << "Out of range, can only insert between index 1 and " << index
            << std::endl;
}

void MyLinkedList::deleteNode(int position) {
  int index{1};

  if (isEmpty()) {
    std::cout << "Can't delete node in a empty list" << std::endl;
    return;
  }

  // Handle edge case: delete head
  if (position == index) {
    Node *tmp = head;
    head = head->next;
    delete tmp;
    return;
  }

  // Regular delete at nth position
  Node *current = head;
  while (current->next != NULL) {
    if (index == position - 1) {
      Node *tmp = current->next;
      current->next = current->next->next;
      delete tmp;
      return;
    }
    index++;
    current = current->next;
  }
  std::cout << "Out of range, can only insert between index 1 and " << index
            << std::endl;
}

void MyLinkedList::printList() {
  if (isEmpty()) {
    std::cout << "List is empty." << std::endl;
    return;
  }

  Node *current = head;
  while (current != NULL) {
    std::cout << current->data << ' ';
    current = current->next;
  }
  std::cout << std::endl;
}

void MyLinkedList::reverse() {
  Node *current = head;
  Node *prev = NULL;
  while (current != NULL) {
    Node *next = current->next;
    current->next = prev;
    prev = current;
    current = next;
  }
  head = prev;
}

void MyLinkedList::reverseRecursive(Node *prev) {
  // If we hit the end of the list set the end as new head
  if (prev->next == NULL) {
    head = prev;
    return;
  }

  // Recursively go through the list
  reverseRecursive(prev->next);

  // Save the next node in a temporary variable and set its next address to
  // the previous node then set the link of the prev to NULL to avoid a
  // infinite loop
  Node *nextNode = prev->next;
  nextNode->next = prev;
  prev->next = NULL;
}
