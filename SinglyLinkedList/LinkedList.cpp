//
// Created by Sedo on 2.12.2025.
//

#include "LinkedList.h"

// Constructor: başlangıçta liste boş
LinkedList::LinkedList() : head(nullptr) {}

// Destructor: tüm düğümleri tek tek silerek belleği temizler
LinkedList::~LinkedList() {
    Node* current = head;
    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp; // her düğüm için delete çağırıyoruz
    }
}

// 1) Listeyi yazdırma
void LinkedList::printList() const {
    Node* current = head;
    std::cout << "Liste: ";
    while (current != nullptr) {
        std::cout << current->data << " -> ";
        current = current->next;
    }
    std::cout << "NULL" << std::endl;
}

// 2) Başa ekleme
void LinkedList::push_front(int value) {
    Node* newNode = new Node(value); // yeni düğüm oluştur
    newNode->next = head;            // yeni düğümün next'i eski head olsun
    head = newNode;                  // head artık bu düğüm
}

// 3) Sona ekleme
void LinkedList::push_back(int value) {
    Node* newNode = new Node(value);

    // Liste boşsa, head direkt bu düğüm olur
    if (head == nullptr) {
        head = newNode;
        return;
    }

    // Boş değilse, sona kadar git
    Node* current = head;
    while (current->next != nullptr) {
        current = current->next;
    }

    // Son düğümün next'ine yeni düğümü bağla
    current->next = newNode;
}

// 4) Araya ekleme: afterValue değerine sahip düğümden SONRA ekle
void LinkedList::insert_after(int afterValue, int newValue) {
    if (head == nullptr) {
        std::cout << "Liste bos, araya ekleme yapilamadi." << std::endl;
        return;
    }

    // afterValue'yu arıyoruz
    Node* current = head;
    while (current != nullptr && current->data != afterValue) {
        current = current->next;
    }

    if (current == nullptr) {
        std::cout << afterValue << " degeri listede bulunamadi, araya eklenemedi." << std::endl;
        return;
    }

    // Bulduktan sonra yeni düğümü araya sok
    Node* newNode = new Node(newValue);
    newNode->next = current->next; // yeni düğümün next'i, current'in next'i olsun
    current->next = newNode;       // current'in next'i artık newNode
}

// 5) Baştan silme
void LinkedList::pop_front() {
    if (head == nullptr) {
        std::cout << "Liste zaten bos, bastan silinemedi." << std::endl;
        return;
    }

    Node* temp = head;
    head = head->next; // head'i bir sonrakine kaydır
    delete temp;       // eski head'i bellekten sil
}

// 6) Belirli bir değeri silme (eşleşen ilk düğüm)
void LinkedList::remove_value(int value) {
    if (head == nullptr) {
        std::cout << "Liste bos, silinecek eleman yok." << std::endl;
        return;
    }

    // Özel durum: baştaki düğüm silinecekse
    if (head->data == value) {
        Node* temp = head;
        head = head->next;
        delete temp;
        std::cout << value << " degerine sahip dugum bastan silindi." << std::endl;
        return;
    }

    // Genel durum: ortada/sonda bir yerdeyse
    Node* current = head;
    Node* prev = nullptr;

    while (current != nullptr && current->data != value) {
        prev = current;
        current = current->next;
    }

    // Bulunamadıysa
    if (current == nullptr) {
        std::cout << value << " degerine sahip dugum bulunamadi." << std::endl;
        return;
    }

    // Bulundu: prev -> current -> current->next
    prev->next = current->next; // current'i zincirden çıkar
    delete current;             // ve sil
    std::cout << value << " degerine sahip dugum silindi." << std::endl;
}
