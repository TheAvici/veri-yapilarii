#include "CircularPlaylist.h"
#include <iostream>

CircularPlaylist::CircularPlaylist()
    : tail(nullptr), current(nullptr) {}

CircularPlaylist::~CircularPlaylist() {
    if (!tail) return;
    Song* head = tail->next;
    Song* cur = head;
    do {
        Song* next = cur->next;
        delete cur;
        cur = next;
    } while (cur != head);
}

void CircularPlaylist::addSong(const std::string& title) {
    Song* node = new Song(title);
    if (!tail) {
        tail = node;
        node->next = node;
        current = node;
    } else {
        node->next = tail->next;
        tail->next = node;
        tail = node;
    }
    std::cout << "Sarki eklendi: " << title << "\n";
}

void CircularPlaylist::nextSong() {
    if (!current) {
        std::cout << "Liste bos.\n";
        return;
    }
    current = current->next; // dairesel oldugu icin repeat
    std::cout << "Sonraki (repeat) sarki: " << current->title << "\n";
}

void CircularPlaylist::showCurrent() const {
    if (current) {
        std::cout << "Calan sarki: " << current->title << "\n";
    } else {
        std::cout << "Sarki yok.\n";
    }
}
