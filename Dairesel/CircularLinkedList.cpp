#include "CircularLinkedList.h"
#include <iostream>

CircularLinkedList::CircularLinkedList()
    : tail(nullptr) {}

CircularLinkedList::~CircularLinkedList() {
    if (!tail) return;
    Node* head = tail->next;
    Node* cur = head;
    do {
        Node* next = cur->next;
        delete cur;
        cur = next;
    } while (cur != head);
}

bool CircularLinkedList::empty() const {
    return tail == nullptr;
}

void CircularLinkedList::push_back(int value) {
    Node* node = new Node(value);
    if (!tail) {
        tail = node;
        node->next = node; // tek eleman, kendine bağlanır
    } else {
        node->next = tail->next;
        tail->next = node;
        tail = node;
    }
}

void CircularLinkedList::printOnce() const {
    if (!tail) {
        std::cout << "Liste bos.\n";
        return;
    }
    Node* head = tail->next;
    Node* cur = head;
    std::cout << "Dairesel Liste: ";
    do {
        std::cout << cur->data << " -> ";
        cur = cur->next;
    } while (cur != head);
    std::cout << "(basa doner)\n";
}
