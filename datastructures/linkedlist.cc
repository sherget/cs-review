// Copyright (c) 2022 Somebody. All rights reserved.

#include "linkedlist.h"
#include <iostream>

class MyLinkedList {
    public:
        struct Node {
            int data{};
            Node *next{NULL};
        };
        Node *head{NULL};
    public:
        MyLinkedList() = default;

        bool isEmpty(){
            if (head == NULL) {
                return true;
            }
            return false;
        }

        // void addNode(int data, int position) {}
        // void deleteNode(int position) {}
        // void printList() {}
        // reverse(){}
        // reverseRecursive(Node *previous) {}
};

int main() {
    return 0;
}
