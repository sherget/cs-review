#ifndef MYARRAYSTACK_H
#define MYARRAYSTACK_H

#include <array>
#include <iostream>

class MyArrayStack {
private:
  std::array<int, 10> stack{};
  int index{-1};

public:
  MyArrayStack() = default;
  bool isEmpty() const { return (index == -1 ? true : false); }
  int top() const;
  void push(int data);
  void pop();
  void printStack();
  void resizeArray();
};

#endif // MYARRAYSTACK_H
