//
// Created by Sedo on 2.12.2025.
//

#include "DoublyLinkedList.h"

// Yapıcı: baş ve son nullptr
DoublyLinkedList::DoublyLinkedList() : head(nullptr), tail(nullptr) {}

// Yıkıcı: tüm düğümleri sırayla sil
DoublyLinkedList::~DoublyLinkedList() {
    Node* current = head;
    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
}

// 1) Listeyi baştan sona yazdır
void DoublyLinkedList::printList() const {
    Node* current = head;
    std::cout << "Liste (ileri): ";
    while (current != nullptr) {
        std::cout << current->data << " <-> ";
        current = current->next;
    }
    std::cout << "NULL" << std::endl;
}

// BONUS: Listeyi sondan başa yazdır (çift yönlünün güzelliği)
void DoublyLinkedList::printReverse() const {
    Node* current = tail;
    std::cout << "Liste (geri):  ";
    while (current != nullptr) {
        std::cout << current->data << " <-> ";
        current = current->prev;
    }
    std::cout << "NULL" << std::endl;
}

// 2) Başa ekleme
void DoublyLinkedList::push_front(int value) {
    Node* newNode = new Node(value);

    newNode->next = head;   // yeni düğümün next'i eski head
    newNode->prev = nullptr;

    if (head != nullptr) {
        head->prev = newNode;
    } else {
        // Liste boşsa hem head hem tail bu düğüm
        tail = newNode;
    }

    head = newNode;
}

// 3) Sona ekleme
void DoublyLinkedList::push_back(int value) {
    Node* newNode = new Node(value);

    newNode->next = nullptr;
    newNode->prev = tail;

    if (tail != nullptr) {
        tail->next = newNode;
    } else {
        // Liste boşsa hem head hem tail bu düğüm
        head = newNode;
    }

    tail = newNode;
}

// 4) Araya ekleme: afterValue düğümünden SONRA newValue ekle
void DoublyLinkedList::insert_after(int afterValue, int newValue) {
    if (head == nullptr) {
        std::cout << "Liste bos, araya ekleme yapilamadi." << std::endl;
        return;
    }

    // afterValue'yu ara
    Node* current = head;
    while (current != nullptr && current->data != afterValue) {
        current = current->next;
    }

    if (current == nullptr) {
        std::cout << afterValue << " degeri listede bulunamadi, araya eklenemedi." << std::endl;
        return;
    }

    Node* newNode = new Node(newValue);

    newNode->prev = current;
    newNode->next = current->next;

    if (current->next != nullptr) {
        current->next->prev = newNode;
    } else {
        // current zaten tail ise, yeni tail bu düğüm olur
        tail = newNode;
    }

    current->next = newNode;
}

// 5) Baştan silme
void DoublyLinkedList::pop_front() {
    if (head == nullptr) {
        std::cout << "Liste zaten bos, bastan silinemedi." << std::endl;
        return;
    }

    Node* temp = head;
    head = head->next;

    if (head != nullptr) {
        head->prev = nullptr;
    } else {
        // Liste tamamen boşaldıysa tail de nullptr olmalı
        tail = nullptr;
    }

    delete temp;
}

// 6) Belirli bir değeri silme
void DoublyLinkedList::remove_value(int value) {
    if (head == nullptr) {
        std::cout << "Liste bos, silinecek eleman yok." << std::endl;
        return;
    }

    // Özel durum: baştaki düğüm silinecekse
    if (head->data == value) {
        pop_front();
        std::cout << value << " degerine sahip dugum bastan silindi." << std::endl;
        return;
    }

    // Ortadaki / sondaki düğümler için
    Node* current = head->next; // head zaten kontrol edildi

    while (current != nullptr && current->data != value) {
        current = current->next;
    }

    if (current == nullptr) {
        std::cout << value << " degerine sahip dugum bulunamadi." << std::endl;
        return;
    }

    // current: silinecek düğüm
    Node* prevNode = current->prev;
    Node* nextNode = current->next;

    if (prevNode != nullptr) {
        prevNode->next = nextNode;
    }

    if (nextNode != nullptr) {
        nextNode->prev = prevNode;
    } else {
        // nextNode yoksa current tail'di, yeni tail prevNode olur
        tail = prevNode;
    }

    delete current;
    std::cout << value << " degerine sahip dugum silindi." << std::endl;

}