//
// Created by Sedo on 2.12.2025.
//

#ifndef SINGLYLINKEDLIST_LINKEDLIST_H
#define SINGLYLINKEDLIST_LINKEDLIST_H

#include <iostream>

class LinkedList {
    private:
    // Tek yönlü düğüm yapısı
    struct Node {
        int data;      // Düğümde tutulan veri
        Node* next;    // Sonraki düğümü gösteren pointer

        Node(int value) : data(value), next(nullptr) {}
    };

    Node* head; // Listenin başını gösterir

    public:
    // Yapıcı (constructor) - listenin başını nullptr yap
    LinkedList();

    // Yıkıcı (destructor) - tüm düğümleri bellekten temizle
    ~LinkedList();

    // 1) Listeyi yazdırma
    void printList() const;

    // 2) Başa ekleme
    void push_front(int value);

    // 3) Sona ekleme
    void push_back(int value);

    // 4) Araya ekleme (belirli bir değerden sonra)
    void insert_after(int afterValue, int newValue);

    // 5) Baştan silme
    void pop_front();

    // 6) Belirli bir değeri silme (eşleşen ilk düğümü siler)
    void remove_value(int value);
};


#endif //SINGLYLINKEDLIST_LINKEDLIST_H