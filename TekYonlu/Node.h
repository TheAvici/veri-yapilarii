//
// Created by Sedo on 2.12.2025.
//

#ifndef TEKYONLU_NODE_H
#define TEKYONLU_NODE_H

struct Node {
    int data;
    Node* next;

    Node(int d) : data(d), next(nullptr) {}
};

#endif //TEKYONLU_NODE_H