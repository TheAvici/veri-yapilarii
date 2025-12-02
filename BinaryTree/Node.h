//
// Created by Sedo on 2.12.2025.
//

#ifndef BINARYTREE_NODE_H
#define BINARYTREE_NODE_H

// Basit binary tree düğümü
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

#endif //BINARYTREE_NODE_H