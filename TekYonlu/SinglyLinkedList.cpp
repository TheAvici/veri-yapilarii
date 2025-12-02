#include "SinglyLinkedList.h"
#include <iostream>
using namespace std;

SinglyLinkedList::SinglyLinkedList()
    : head(nullptr), tail(nullptr)
{
    // cout << "SinglyLinkedList() cagrildi." << endl;
}

SinglyLinkedList::~SinglyLinkedList() {
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
    // cout << "Liste hafizadan temizlendi." << endl;
}

void SinglyLinkedList::push_front(int data) {
    Node* newNode = new Node(data);
    newNode->next = head;
    head = newNode;

    if (tail == nullptr) {
        tail = head;
    }
}

void SinglyLinkedList::push_back(int data) {
    Node* newNode = new Node(data);

    if (head == nullptr) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

void SinglyLinkedList::printList() const {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

// ---------- İkinci uygulama: insert_after, deleteNode ----------

void SinglyLinkedList::insert_after(Node* prev_node, int data) {
    if (prev_node == nullptr) {
        cout << "Hata: prev_node NULL olamaz. Ekleme yapilmadi." << endl;
        return;
    }

    Node* newNode = new Node(data);
    newNode->next = prev_node->next;
    prev_node->next = newNode;

    if (prev_node == tail) {
        tail = newNode;
    }
}

void SinglyLinkedList::deleteNode(int key) {
    if (head == nullptr) {
        cout << "Liste bos, silinecek eleman yok." << endl;
        return;
    }

    Node* temp = head;
    Node* prev = nullptr;

    // Silinecek dugum bastaysa
    if (temp != nullptr && temp->data == key) {
        head = temp->next;
        if (temp == tail) {
            tail = nullptr;
        }
        delete temp;
        return;
    }

    // Ortada/sonda arama
    while (temp != nullptr && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "Bilgi: " << key << " degerli eleman listede bulunamadi." << endl;
        return;
    }

    prev->next = temp->next;
    if (temp == tail) {
        tail = prev;
    }
    delete temp;
}
