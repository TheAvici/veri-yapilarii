#include "DoublyLinkedList.h"
#include <iostream>

DoublyLinkedList::DoublyLinkedList()
    : head(nullptr), tail(nullptr) {}

DoublyLinkedList::~DoublyLinkedList() {
    Node* cur = head;
    while (cur) {
        Node* next = cur->next;
        delete cur;
        cur = next;
    }
}

bool DoublyLinkedList::empty() const {
    return head == nullptr;
}

void DoublyLinkedList::push_front(int value) {
    Node* node = new Node(value);
    if (empty()) {
        head = tail = node;
    } else {
        node->next = head;
        head->prev = node;
        head = node;
    }
}

void DoublyLinkedList::push_back(int value) {
    Node* node = new Node(value);
    if (empty()) {
        head = tail = node;
    } else {
        tail->next = node;
        node->prev = tail;
        tail = node;
    }
}

bool DoublyLinkedList::remove(int value) {
    Node* cur = head;
    while (cur && cur->data != value) {
        cur = cur->next;
    }
    if (!cur) return false;

    if (cur->prev) cur->prev->next = cur->next;
    else head = cur->next;

    if (cur->next) cur->next->prev = cur->prev;
    else tail = cur->prev;

    delete cur;
    return true;
}

void DoublyLinkedList::printForward() const {
    Node* cur = head;
    std::cout << "Forward: ";
    while (cur) {
        std::cout << cur->data << " <-> ";
        cur = cur->next;
    }
    std::cout << "NULL\n";
}

void DoublyLinkedList::printBackward() const {
    Node* cur = tail;
    std::cout << "Backward: ";
    while (cur) {
        std::cout << cur->data << " <-> ";
        cur = cur->prev;
    }
    std::cout << "NULL\n";
}
