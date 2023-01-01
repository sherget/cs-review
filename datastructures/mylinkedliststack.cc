#include "mylinkedliststack.h"

int MyLinkedListStack::top() const {
  if (!isEmpty()) {
    return head->data;
  }
  std::cout << "Stack is empty!" << std::endl;
  return -1;
}

void MyLinkedListStack::printStack() const {
    if (isEmpty()) {
       std::cout << "Stack is empty!" << std::endl;
       return;
    }
  Node *current = head;
  while (current != NULL) {
    std::cout << current->data << ' ';
    current = current->next;
  }
  std::cout << std::endl;
}

void MyLinkedListStack::push(const int data) {
  if (isEmpty()) {
    head = new Node{data, NULL};
    return;
  }

  Node *tmp{new Node{data, head}};
  head = tmp;
}

void MyLinkedListStack::pop() {
  if (isEmpty()) {
    std::cout << "Can't pop from empty stack!" << std::endl;
    return;
  }
  Node *tmp = head;
  head = head->next;
  delete tmp;
}
