#include "BrowserHistory.h"
#include <iostream>
#include "Page.h"

BrowserHistory::BrowserHistory()
    : head(nullptr), tail(nullptr), current(nullptr) {}

BrowserHistory::~BrowserHistory() {
    Node* cur = head;
    while (cur) {
        Node* next = cur->next;
        delete cur;
        cur = next;
    }
}

void BrowserHistory::removeForward(Node* from) {
    Node* cur = from;
    while (cur) {
        Node* next = cur->next;
        delete cur;
        cur = next;
    }
    if (from && from->prev) {
        from->prev->next = nullptr;
        tail = from->prev;
    }
}

void BrowserHistory::visit(const Page& page) {
    // current'tan sonraki tüm sayfaları sil
    if (current && current->next) {
        removeForward(current->next);
    }

    Node* node = new Node(page);

    if (!head) {
        head = tail = node;
    } else {
        tail->next = node;
        node->prev = tail;
        tail = node;
    }

    std::cout << "Ziyaret: " << page.title << " (" << page.url << ")\n";
}

void BrowserHistory::back() {
    if (current && current->prev) {
        current = current->prev;
        // 🔴 ESKİ: current->title
        std::cout << "Geri -> " << current->data.title << "\n";
    } else {
        std::cout << "Geri gidilemiyor.\n";
    }
}

void BrowserHistory::forward() {
    if (current && current->next) {
        current = current->next;
        // 🔴 ESKİ: current->title
        std::cout << "Ileri -> " << current->data.title << "\n";
    } else {
        std::cout << "Ileri gidilemiyor.\n";
    }
}

void BrowserHistory::showCurrent() const {
    if (current) {
        // 🔴 ESKİ: current->title ve current->url
        std::cout << "Aktif sayfa: " << current->data.title
                  << " (" << current->data.url << ")\n";
    } else {
        std::cout << "Sayfa yok.\n";
    }
}
