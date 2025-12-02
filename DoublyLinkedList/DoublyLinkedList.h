//
// Created by Sedo on 2.12.2025.
//

#ifndef DOUBLYLINKEDLIST_DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_DOUBLYLINKEDLIST_H

#include <iostream>

class DoublyLinkedList {
private:
    // Çift yönlü düğüm yapısı
    struct Node {
        int data;
        Node* prev;
        Node* next;

        Node(int value) : data(value), prev(nullptr), next(nullptr) {}
    };

    Node* head; // listenin başı
    Node* tail; // listenin sonu (sona eklemeyi O(1) yapar)

public:
    // Yapıcı ve yıkıcı
    DoublyLinkedList();
    ~DoublyLinkedList();

    // 1) Listeyi ileri yönde yazdır
    void printList() const;

    // (Bonus istersen kullanırsın) Listeyi tersten yazdır
    void printReverse() const;

    // 2) Başa ekleme
    void push_front(int value);

    // 3) Sona ekleme
    void push_back(int value);

    // 4) Araya ekleme (afterValue değerinden SONRA newValue ekle)
    void insert_after(int afterValue, int newValue);

    // 5) Baştan silme
    void pop_front();

    // 6) Belirli bir değeri silme (eşleşen ilk düğüm)
    void remove_value(int value);
};


#endif //DOUBLYLINKEDLIST_DOUBLYLINKEDLIST_H