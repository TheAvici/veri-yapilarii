#include "AVLTree.h"
#include <iostream>
#include <algorithm> // max
using namespace std;

// ===== AVLNode =====
AVLNode::AVLNode(int k)
    : key(k), height(1), left(nullptr), right(nullptr) {}

// ===== AVLTree =====
AVLTree::AVLTree() : root(nullptr) {}

AVLTree::~AVLTree() {
    freeTree(root);
}

void AVLTree::insert(int key) {
    root = insertRec(root, key);
}

void AVLTree::printInorder() const {
    inorderRec(root);
    cout << endl;
}

int AVLTree::getHeight(AVLNode* node) const {
    return node ? node->height : 0;
}

int AVLTree::getBalance(AVLNode* node) const {
    if (!node) return 0;
    return getHeight(node->left) - getHeight(node->right);
}

void AVLTree::updateHeight(AVLNode* node) {
    if (!node) return;
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));
}

// Sağ rotasyon
AVLNode* AVLTree::rightRotate(AVLNode* y) {
    AVLNode* x = y->left;
    AVLNode* T2 = x->right;

    x->right = y;
    y->left = T2;

    updateHeight(y);
    updateHeight(x);

    return x;
}

// Sol rotasyon
AVLNode* AVLTree::leftRotate(AVLNode* y) {
    AVLNode* x = y->right;
    AVLNode* T2 = x->left;

    x->left = y;
    y->right = T2;

    updateHeight(y);
    updateHeight(x);

    return x;
}

AVLNode* AVLTree::insertRec(AVLNode* node, int key) {
    // 1) Normal BST insert
    if (node == nullptr) {
        return new AVLNode(key);
    }

    if (key < node->key)
        node->left = insertRec(node->left, key);
    else if (key > node->key)
        node->right = insertRec(node->right, key);
    else
        return node; // duplicate eklemiyoruz

    // 2) height güncelle
    updateHeight(node);

    // 3) balance kontrol
    int balance = getBalance(node);

    // Left Left
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    // Right Right
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    // Left Right
    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left
    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    // Dengeli ise node’u aynen döndür
    return node;
}

void AVLTree::inorderRec(AVLNode* node) const {
    if (!node) return;
    inorderRec(node->left);
    cout << node->key << "(" << node->height << ") ";
    inorderRec(node->right);
}

void AVLTree::freeTree(AVLNode* node) {
    if (!node) return;
    freeTree(node->left);
    freeTree(node->right);
    delete node;
}
