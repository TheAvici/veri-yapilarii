//
// Created by Sedo on 2.12.2025.
//

#ifndef DAIRESEL_CIRCULARLINKEDLIST_H
#define DAIRESEL_CIRCULARLINKEDLIST_H


#include "Node.h"

class CircularLinkedList {
private:
    Node* tail; // tail->next = head

public:
    CircularLinkedList();
    ~CircularLinkedList();

    bool empty() const;
    void push_back(int value);
    void printOnce() const; // bir tur yaz
};


#endif //DAIRESEL_CIRCULARLINKEDLIST_H