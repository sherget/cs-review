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

        void addNode(int data, int position) {
            int index{1};

            // Add initial node
            if (isEmpty()) {
                head = new Node{data, NULL};
                return;
            }

            // Handle edge case: insert at head
            if (position == index) {
                Node *tmp = new Node{data,head};
                head = tmp;
                return;
            }

            // Regular inserts at nth position
            Node *current = head;
            while (current != NULL) {
                if (index == position-1) {
                   Node *tmp = new Node{data,current->next};
                   current->next = tmp;
                   return;
                }
               index++;
               current = current->next;
            }

            std::cout << "Out of range, can only insert between index 1 and " << index << std::endl;
        }

        void deleteNode(int position) {
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
                if (index == position-1) {
                   Node *tmp = current->next;
                   current->next = current->next->next;
                   delete tmp;
                   return;
                }
                index++;
               current = current->next;
            }
            std::cout << "Out of range, can only insert between index 1 and " << index << std::endl;
        }

        void printList() {
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
        // reverse(){}
        // reverseRecursive(Node *previous) {}
};

int main() {
    MyLinkedList ll;

    std::cout << "Create linked list:" << std::endl;
    ll.printList();
    ll.addNode(4,1);
    ll.addNode(6,1);
    ll.addNode(8,1);
    ll.addNode(13,2);
    ll.addNode(37,3);
    ll.addNode(100,6);
    ll.addNode(99,99); // Error out of range
    ll.printList();

    std::cout << '\n';
    ll.deleteNode(3);
    ll.printList();
    ll.deleteNode(1);
    ll.printList();
    ll.deleteNode(1);
    ll.deleteNode(20); // Error out of range
    ll.printList();

    return 0;
}
