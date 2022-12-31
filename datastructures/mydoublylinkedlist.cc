#include "mydoublylinkedlist.h"

void MyDoublyLinkedList::printList() const {
  if (isEmpty()) {
    std::cout << "List is empty." << std::endl;
    return;
  }
  Node *current = head;
  while (current != NULL) {
    if (current->prev != NULL) {
      std::cout << current->prev->data << "<-";
    } else {
      std::cout << "   ";
    }
    std::cout << current->data << "->";
    if (current->next != NULL) {
      std::cout << current->next->data << ' ';
    } else {
      std::cout << "   ";
    }
    std::cout << std::endl;
    current = current->next;
  }
  std::cout << std::endl;
}

void MyDoublyLinkedList::addNode(int data, int position) {
  int index{1};

  // Add initial node
  if (isEmpty()) {
    head = new Node{data, NULL, NULL};
    return;
  }

  // Handle edge case: insert at head
  if (position == index) {
    Node *tmp = new Node{data, NULL, head};
    head->prev = tmp;
    head = tmp;
    return;
  }

  // Regular inserts at nth position
  Node *current = head;
  while (current != NULL) {
    if (index == position - 1) {
      Node *tmp = new Node{data, current, current->next};
      current->next->prev = tmp;
      current->next = tmp;
      return;
    }
    index++;
    current = current->next;
  }

  std::cout << "Out of range, can only insert between index 1 and " << index
            << std::endl;
}

void MyDoublyLinkedList::deleteNode(int position) {
  int index{1};

  if (isEmpty()) {
    std::cout << "Can't delete node in a empty list" << std::endl;
    return;
  }

  // Handle edge case: delete head
  if (position == index) {
    Node *tmp = head;
    head->prev = NULL;
    head->next->prev = NULL;
    head = head->next;
    delete tmp;
    return;
  }

  // Regular delete at nth position
  Node *current = head;
  while (current->next != NULL) {
    if (index == position - 1) {
      Node *tmp = current->next;
      tmp->prev = NULL;
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

void MyDoublyLinkedList::reverse() {
  Node *current = head;
  Node *prev = NULL;
  while (current != NULL) {
    Node *nextNode = current->next;
    current->next = prev;
    prev = current;
    current->prev = nextNode;
    current = nextNode;
  }
  head = prev;
  head->prev = NULL;
}
