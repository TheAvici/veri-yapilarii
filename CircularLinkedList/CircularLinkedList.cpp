//
// Created by Sedo on 2.12.2025.
//

#include "CircularLinkedList.h"


// Yapıcı: başlangıçta boş liste
CircularLinkedList::CircularLinkedList() : head(nullptr), tail(nullptr) {}

// Yıkıcı: tüm düğümleri sil
CircularLinkedList::~CircularLinkedList() {
    if (head == nullptr) {
        return; // Zaten boş
    }

    // Dairesel listede tüm düğümleri tek tek dolaş ve sil
    Node* current = head->next;
    while (current != head) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }

    // Son olarak head'i sil
    delete head;
    head = nullptr;
    tail = nullptr;
}

// 1) Listeyi yazdırma
void CircularLinkedList::printList() const {
    if (head == nullptr) {
        std::cout << "Liste bos." << std::endl;
        return;
    }

    std::cout << "Liste: ";
    Node* current = head;
    // En az bir düğüm var, dairesel olduğu için do-while kullanıyoruz
    do {
        std::cout << current->data << " -> ";
        current = current->next;
    } while (current != head);

    std::cout << "(geri donus head)" << std::endl;
}

// 2) Başa ekleme
void CircularLinkedList::push_front(int value) {
    Node* newNode = new Node(value);

    if (head == nullptr) {
        // İlk eleman
        head = tail = newNode;
        newNode->next = newNode; // kendini gösterir (dairesel)
    } else {
        newNode->next = head;
        head = newNode;
        tail->next = head; // dairesellik devam etsin
    }
}

// 3) Sona ekleme
void CircularLinkedList::push_back(int value) {
    Node* newNode = new Node(value);

    if (head == nullptr) {
        // İlk eleman
        head = tail = newNode;
        newNode->next = newNode;
    } else {
        newNode->next = head;  // yeni tail'in next'i head'i göstermeli
        tail->next = newNode;  // eski tail yeni düğüme bağlanır
        tail = newNode;        // tail güncellenir
    }
}

// 4) Araya ekleme: afterValue düğümünden SONRA newValue ekle
void CircularLinkedList::insert_after(int afterValue, int newValue) {
    if (head == nullptr) {
        std::cout << "Liste bos, araya ekleme yapilamadi." << std::endl;
        return;
    }

    Node* current = head;
    bool found = false;

    // Dairesel döngü: tüm listeyi bir kez dolaş
    do {
        if (current->data == afterValue) {
            found = true;
            break;
        }
        current = current->next;
    } while (current != head);

    if (!found) {
        std::cout << afterValue << " degeri listede bulunamadi, araya eklenemedi." << std::endl;
        return;
    }

    Node* newNode = new Node(newValue);
    newNode->next = current->next;
    current->next = newNode;

    // Eğer afterValue tail'de ise, tail güncellenmeli
    if (current == tail) {
        tail = newNode;
    }
}

// 5) Baştan silme
void CircularLinkedList::pop_front() {
    if (head == nullptr) {
        std::cout << "Liste zaten bos, bastan silinemedi." << std::endl;
        return;
    }

    // Tek eleman varsa
    if (head == tail) {
        delete head;
        head = nullptr;
        tail = nullptr;
        return;
    }

    // Birden fazla eleman varsa
    Node* temp = head;
    head = head->next;
    tail->next = head; // dairesellik devam etsin
    delete temp;
}

// 6) Belirli bir değeri silme
void CircularLinkedList::remove_value(int value) {
    if (head == nullptr) {
        std::cout << "Liste bos, silinecek eleman yok." << std::endl;
        return;
    }

    // Özel durum: head silinecekse
    if (head->data == value) {
        // Tek eleman durumu
        if (head == tail) {
            delete head;
            head = nullptr;
            tail = nullptr;
        } else {
            Node* temp = head;
            head = head->next;
            tail->next = head; // dairesellik devam etsin
            delete temp;
        }
        std::cout << value << " degerine sahip dugum bastan silindi." << std::endl;
        return;
    }

    // Genel durum: head dışındaki düğümler
    Node* prev = head;
    Node* current = head->next;

    // Dairesel döngü: tekrar head'e gelene kadar dolaş
    while (current != head && current->data != value) {
        prev = current;
        current = current->next;
    }

    if (current == head) {
        // Baştan tekrar başa geldik, bulunamadı
        std::cout << value << " degerine sahip dugum bulunamadi." << std::endl;
        return;
    }

    // current silinecek düğüm
    prev->next = current->next;

    // Eğer tail siliniyorsa, yeni tail prev olmalı
    if (current == tail) {
        tail = prev;
    }

    delete current;
    std::cout << value << " degerine sahip dugum silindi." << std::endl;
}
