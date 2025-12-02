#include "Playlist.h"
#include <iostream>
#include "Song.h"
#include "Node.h"

using namespace std;

PlayList::PlayList() {
    head = nullptr;
    currentSong = nullptr;
    isRepeat = false;
}

PlayList::~PlayList() {
    if (!head) return;

    Node* tail = head->prev;
    tail->next = nullptr;
    head->prev = nullptr;

    Node* current = head;
    while (current != nullptr) {
        Node* nextNode = current->next;
        delete current;
        current = nextNode;
    }
    cout << "\n(Liste hafizadan silindi.)" << endl;
}
void PlayList::addSong(Song song) {
    Song newSong = Song(song.title, song.artist);
    Node* newNode = new Node(newSong);

    if (head == nullptr) {
        head = newNode;
        head -> next = head;
        head -> prev = head;
        currentSong = head;
    }
    else {
        Node *last = head -> prev;
        newNode -> next = head;

        newNode -> prev = last;
        head ->prev = newNode;
        last -> next = newNode;
    }
    cout <<  "Sarki eklendi!" << endl;
}

bool PlayList::removeSong(string title) {
    if (head == nullptr) return false;

    Node* temp = head;
    do {
        if (temp->data.title == title) {
            if (temp->next == temp) {
                delete temp;
                head = nullptr;
                currentSong = nullptr;
            }
            else {
                Node* prevNode = temp->prev;
                Node* nextNode = temp->next;

                prevNode->next = nextNode;
                nextNode->prev = prevNode;

                if (temp == head) {
                    head = nextNode;
                }
                if (temp == currentSong) {
                    currentSong = nextNode;
                }
                delete temp;
            }
            cout << "[Silindi]: " << title << endl;
            return true;
        }
        temp = temp->next;
    } while (temp != head);

    cout << "[Bulunamadi]: " << title << endl;
    return false;
}

void PlayList::playCurrent() {
    if (currentSong == nullptr) {
        cout << "Listede calacak sarki bulunamadi." << endl;
    } else {
        cout << "Su an calan sarki: " << currentSong->data.title << "( " << currentSong->data.artist << " )"<< endl;
    }
}

void PlayList::nextSong() {
    if (currentSong == nullptr) {
        return;
    }
    if (!isRepeat && currentSong -> next == head) {
        cout << "Sirada sarki yok (Tekrar modu kapali)." << endl;
    }else {
        currentSong = currentSong -> next;
        playCurrent();
    }
}

void PlayList::prevSong() {
    if (currentSong == nullptr) {
        return;
    }
    if (!isRepeat && currentSong == head) {
        cout << "Listenin basi. (Tekrar modu kapali)." << endl;
    } else {
        currentSong = currentSong->prev;
        playCurrent();
    }
}

void PlayList::toggleRepeat() {
    isRepeat = !isRepeat;
    cout << "\nTekrar modu: " << (isRepeat ? "Acik" : "Kapali") << endl;
}

void PlayList::printPlaylist() {
    if (head == nullptr) {
        cout << "Liste bos." << endl;
        return;
    }
    Node* temp = head;
    cout << "-------Sarki Listen-------" << endl;
    int i = 1;
    do {
        cout << (temp == currentSong ? "-> " : " ");
        cout << i++ << "-" << temp->data.title << " (" << temp->data.artist << ")" << endl;
        temp = temp -> next;
    }while (temp != head);
    cout << "--------------------------" << endl;
}
