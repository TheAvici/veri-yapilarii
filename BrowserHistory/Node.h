//
// Created by Sedo on 2.12.2025.
//

#ifndef BROWSERHISTORY_NODE_H
#define BROWSERHISTORY_NODE_H

#include "Page.h"

struct Node {
    Page data;
    Node* next;
    Node* prev;

    Node(const Page& d) : data(d), next(nullptr), prev(nullptr) {}
};



#endif //BROWSERHISTORY_NODE_H