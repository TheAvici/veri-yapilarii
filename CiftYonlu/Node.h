//
// Created by Sedo on 2.12.2025.
//

#ifndef CIFTYONLU_NODE_H
#define CIFTYONLU_NODE_H


struct Node {
    int data;
    Node* prev;
    Node* next;

    Node(int d) : data(d), prev(nullptr), next(nullptr) {}
};


#endif //CIFTYONLU_NODE_H