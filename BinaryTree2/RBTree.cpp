#include "RBTree.h"
#include <iostream>
#include <cstdlib> // abs
using namespace std;

// ===== RBNode =====
RBNode::RBNode(int k)
    : key(k), color(RED), left(nullptr), right(nullptr), parent(nullptr) {}

// ===== RBTree =====
RBTree::RBTree() : root(nullptr) {}

RBTree::~RBTree() {
    freeTree(root);
}

void RBTree::insert(int key) {
    // Normal BST insert
    RBNode* z = new RBNode(key);
    RBNode* y = nullptr;
    RBNode* x = root;

    while (x != nullptr) {
        y = x;
        if (key < x->key)
            x = x->left;
        else if (key > x->key)
            x = x->right;
        else {
            // duplicate: eklemiyoruz
            delete z;
            return;
        }
    }

    z->parent = y;
    if (y == nullptr) {
        root = z; // ağaç boştu
    } else if (key < y->key) {
        y->left = z;
    } else {
        y->right = z;
    }

    z->color = RED;
    fixInsert(z);
}

void RBTree::leftRotate(RBNode* x) {
    RBNode* y = x->right;
    if (!y) return;

    x->right = y->left;
    if (y->left != nullptr) {
        y->left->parent = x;
    }

    y->parent = x->parent;
    if (x->parent == nullptr) {
        root = y;
    } else if (x == x->parent->left) {
        x->parent->left = y;
    } else {
        x->parent->right = y;
    }

    y->left = x;
    x->parent = y;
}

void RBTree::rightRotate(RBNode* y) {
    RBNode* x = y->left;
    if (!x) return;

    y->left = x->right;
    if (x->right != nullptr) {
        x->right->parent = y;
    }

    x->parent = y->parent;
    if (y->parent == nullptr) {
        root = x;
    } else if (y == y->parent->left) {
        y->parent->left = x;
    } else {
        y->parent->right = x;
    }

    x->right = y;
    y->parent = x;
}

void RBTree::fixInsert(RBNode* z) {
    while (z->parent != nullptr && z->parent->color == RED) {
        RBNode* parent = z->parent;
        RBNode* grandparent = parent->parent;

        if (grandparent == nullptr) break;

        if (parent == grandparent->left) {
            RBNode* uncle = grandparent->right;

            // Case 1: Amca kırmızı → recolor
            if (uncle != nullptr && uncle->color == RED) {
                parent->color = BLACK;
                uncle->color = BLACK;
                grandparent->color = RED;
                z = grandparent;
            } else {
                // Case 2: z sağ çocuk → sol rotasyon + case 3
                if (z == parent->right) {
                    z = parent;
                    leftRotate(z);
                    parent = z->parent;
                    grandparent = parent ? parent->parent : nullptr;
                }
                // Case 3: z sol çocuk → sağ rotasyon
                if (parent) parent->color = BLACK;
                if (grandparent) {
                    grandparent->color = RED;
                    rightRotate(grandparent);
                }
            }
        } else {
            // Parent sağ çocuk
            RBNode* uncle = grandparent->left;

            if (uncle != nullptr && uncle->color == RED) {
                parent->color = BLACK;
                uncle->color = BLACK;
                grandparent->color = RED;
                z = grandparent;
            } else {
                if (z == parent->left) {
                    z = parent;
                    rightRotate(z);
                    parent = z->parent;
                    grandparent = parent ? parent->parent : nullptr;
                }
                if (parent) parent->color = BLACK;
                if (grandparent) {
                    grandparent->color = RED;
                    leftRotate(grandparent);
                }
            }
        }
    }

    if (root) root->color = BLACK;
}

void RBTree::inorderRec(RBNode* node) const {
    if (!node) return;
    inorderRec(node->left);
    cout << node->key << "(" << (node->color == RED ? "R" : "B") << ") ";
    inorderRec(node->right);
}

void RBTree::printInorder() const {
    inorderRec(root);
    cout << endl;
}

void RBTree::freeTree(RBNode* node) {
    if (!node) return;
    freeTree(node->left);
    freeTree(node->right);
    delete node;
}
