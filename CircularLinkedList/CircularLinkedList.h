//
// Created by Sedo on 2.12.2025.
//

#ifndef CIRCULARLINKEDLIST_CIRCULARLINKEDLIST_H
#define CIRCULARLINKEDLIST_CIRCULARLINKEDLIST_H


#include <iostream>

class CircularLinkedList {
private:
    struct Node {
        int data;
        Node* next;

        Node(int value) : data(value), next(nullptr) {}
    };

    Node* head; // ilk eleman
    Node* tail; // son eleman (tail->next her zaman head'i gösterir)

public:
    // Yapıcı ve yıkıcı
    CircularLinkedList();
    ~CircularLinkedList();

    // 1) Listeyi yazdırma
    void printList() const;

    // 2) Başa ekleme
    void push_front(int value);

    // 3) Sona ekleme
    void push_back(int value);

    // 4) Araya ekleme (afterValue'den SONRA newValue ekle)
    void insert_after(int afterValue, int newValue);

    // 5) Baştan silme
    void pop_front();

    // 6) Belirli bir değeri silme (eşleşen ilk düğüm)
    void remove_value(int value);
};


#endif //CIRCULARLINKEDLIST_CIRCULARLINKEDLIST_H