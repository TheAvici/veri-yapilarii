//
// Created by Sedo on 2.12.2025.
//

#ifndef DAIRESEL_NODE_H
#define DAIRESEL_NODE_H

struct Node {
    int data;
    Node* next;

    Node(int d) : data(d), next(nullptr) {}
};


#endif //DAIRESEL_NODE_H