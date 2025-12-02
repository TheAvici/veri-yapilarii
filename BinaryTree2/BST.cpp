#include "BST.h"
#include <iostream>
using namespace std;

// ===== BSTNode =====
BSTNode::BSTNode(int k) : key(k), left(nullptr), right(nullptr) {}

// ===== BST =====
BST::BST() : root(nullptr) {}

BST::~BST() {
    freeTree(root);
}

void BST::insert(int key) {
    root = insertRec(root, key);
}

bool BST::search(int key) const {
    return searchRec(root, key);
}

void BST::printInorder() const {
    inorderRec(root);
    cout << endl;
}

BSTNode* BST::insertRec(BSTNode* node, int key) {
    if (node == nullptr) {
        return new BSTNode(key);
    }
    if (key < node->key)
        node->left = insertRec(node->left, key);
    else if (key > node->key)
        node->right = insertRec(node->right, key);
    // eşitse ekleme yapmıyoruz
    return node;
}

bool BST::searchRec(BSTNode* node, int key) const {
    if (node == nullptr) return false;
    if (key == node->key) return true;
    if (key < node->key) return searchRec(node->left, key);
    return searchRec(node->right, key);
}

void BST::inorderRec(BSTNode* node) const {
    if (!node) return;
    inorderRec(node->left);
    cout << node->key << " ";
    inorderRec(node->right);
}

void BST::freeTree(BSTNode* node) {
    if (!node) return;
    freeTree(node->left);
    freeTree(node->right);
    delete node;
}
