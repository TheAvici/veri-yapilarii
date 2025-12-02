//
// Created by Sedo on 2.12.2025.
//

#ifndef TEKYONLU_SINGLYLINKEDLIST_H
#define TEKYONLU_SINGLYLINKEDLIST_H

#include "Node.h"

class SinglyLinkedList {
public:
    SinglyLinkedList();
    ~SinglyLinkedList();

    // Kopyalamayi kapat
    SinglyLinkedList(const SinglyLinkedList&) = delete;
    SinglyLinkedList& operator=(const SinglyLinkedList&) = delete;

    void push_front(int data);
    void push_back(int data);
    void printList() const;

    Node* getHead() const { return head; }
    Node* getTail() const { return tail; }

    // İkinci uygulama için:
    void insert_after(Node* prev_node, int data);
    void deleteNode(int key);

private:
    Node* head;
    Node* tail;
};

#endif //TEKYONLU_SINGLYLINKEDLIST_H