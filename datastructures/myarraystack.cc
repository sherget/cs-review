#include "myarraystack.h"

int MyArrayStack::top() const {
  if (isEmpty()) {
    std::cout << "The stack is empty." << std::endl;
    return -1;
  }
  return stack[static_cast<size_t>(index)];
}

void MyArrayStack::push(int data) {
  if (index < static_cast<int>(stack.max_size())) {
    ++index;
    stack[static_cast<size_t>(index)] = data;
    return;
  }
  // Array is full, we have to resize it and copy the values to a larger array.
  std::cout << "Stack is full. We could make use of an dynamic array and "
               "resize the array by copying the current array to a new array "
               "with double the size of the current one. But I'd rather use a "
               "LinkedList implementation of a Stack for this case."
            << std::endl;
};

void MyArrayStack::pop() {
  if (!isEmpty()) {
    --index;
    return;
  }
  std::cout << "Can't pop from empty stack." << std::endl;
}

void MyArrayStack::printStack() {
  if (!isEmpty()) {
    for (auto i{0}; i <= index; ++i) {
      std::cout << stack[static_cast<size_t>(i)] << ' ';
    }
    std::cout << std::endl;
    return;
  }
  std::cout << "The stack is empty, there is nothing to print." << std::endl;
}
