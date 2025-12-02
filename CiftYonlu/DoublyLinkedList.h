//
// Created by Sedo on 2.12.2025.
//

#ifndef CIFTYONLU_DOUBLYLINKEDLIST_H
#define CIFTYONLU_DOUBLYLINKEDLIST_H

#include "Node.h"

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList();
    ~DoublyLinkedList();

    void push_front(int value);
    void push_back(int value);
    bool remove(int value);
    void printForward() const;
    void printBackward() const;
    bool empty() const;
};



#endif //CIFTYONLU_DOUBLYLINKEDLIST_H