#include "RoundRobinScheduler.h"
#include <iostream>

RoundRobinScheduler::RoundRobinScheduler()
    : tail(nullptr) {}

RoundRobinScheduler::~RoundRobinScheduler() {
    if (!tail) return;
    ProcessNode* head = tail->next;
    ProcessNode* cur = head;
    do {
        ProcessNode* next = cur->next;
        delete cur;
        cur = next;
    } while (cur != head);
}

bool RoundRobinScheduler::empty() const {
    return tail == nullptr;
}

void RoundRobinScheduler::addProcess(const std::string& name, int burstTime) {
    ProcessNode* node = new ProcessNode(name, burstTime);
    if (!tail) {
        tail = node;
        node->next = node;
    } else {
        node->next = tail->next;
        tail->next = node;
        tail = node;
    }
    std::cout << "Process eklendi: " << name
              << " (time = " << burstTime << ")\n";
}

void RoundRobinScheduler::run(int quantum) {
    if (!tail) {
        std::cout << "Process yok.\n";
        return;
    }

    std::cout << "\nRound-Robin basladi (quantum = " << quantum << ")\n";

    ProcessNode* prev = tail;
    ProcessNode* current = tail->next;

    while (tail) {
        std::cout << "Calisiyor: " << current->name
                  << " (kalan: " << current->remainingTime << ")\n";

        if (current->remainingTime > quantum) {
            current->remainingTime -= quantum;
            prev = current;
            current = current->next;
            tail = prev;
        } else {
            std::cout << "Process bitti: " << current->name << "\n";
            if (current == prev) {
                // tek eleman kalmissa
                delete current;
                current = nullptr;
                tail = nullptr;
            } else {
                prev->next = current->next;
                if (current == tail) {
                    tail = prev;
                }
                ProcessNode* toDelete = current;
                current = current->next;
                delete toDelete;
            }
        }
    }

    std::cout << "Tum processler tamamlandi.\n";
}
