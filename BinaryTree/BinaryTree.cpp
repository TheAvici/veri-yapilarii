//
// Created by Sedo on 2.12.2025.
//

#include "BinaryTree.h"
#include <queue>
#include <algorithm>  // std::max
#include <cstdlib>    // std::abs
#include <iostream>

using namespace std;

BinaryTree::BinaryTree() : root(nullptr) {}

BinaryTree::~BinaryTree() {
    freeTree(root);
}

void BinaryTree::setRoot(Node* node) {
    // Eski ağacı temizlemek istersen buraya freeTree(root); da koyabilirsin
    root = node;
}

Node* BinaryTree::getRoot() const {
    return root;
}

// ===============================
// Yükseklik
// ===============================
int BinaryTree::height(Node* node) const {
    if (node == nullptr) return -1;      // yaprak yoksa -1, tek düğüm = 0
    return 1 + max(height(node->left), height(node->right));
}

// ===============================
// Proper / Strict Binary Tree
// (Her düğüm 0 veya 2 çocuklu)
// ===============================
bool BinaryTree::isProper(Node* node) const {
    if (node == nullptr) return true;

    bool hasLeft = (node->left != nullptr);
    bool hasRight = (node->right != nullptr);

    // Sadece 1 çocuk varsa proper değil
    if (hasLeft ^ hasRight) { // XOR
        return false;
    }

    // 0 veya 2 çocukluysa alt ağaçlara bak
    return isProper(node->left) && isProper(node->right);
}

bool BinaryTree::isProper() const {
    return isProper(root);
}

// ===============================
// Full Binary Tree
// (Bu örnekte proper ile aynı mantık)
// ===============================
bool BinaryTree::isFull() const {
    return isProper(root);
}

// ===============================
// Perfect Binary Tree
// ===============================
int BinaryTree::leftmostLeafDepth(Node* node) const {
    int d = 0;
    while (node != nullptr) {
        d++;
        node = node->left;
    }
    return d; // seviye sayısı
}

bool BinaryTree::isPerfectUtil(Node* node, int expectedDepth, int level) const {
    if (node == nullptr) return true;

    // Yaprak
    if (node->left == nullptr && node->right == nullptr) {
        // Bütün yapraklar aynı seviyede olmalı
        return (expectedDepth == level + 1);
    }

    // İç düğüm ama tek çocuklu → perfect değil
    if (node->left == nullptr || node->right == nullptr) {
        return false;
    }

    // Hem sol hem sağ var, bir seviye aşağı in
    return isPerfectUtil(node->left, expectedDepth, level + 1) &&
           isPerfectUtil(node->right, expectedDepth, level + 1);
}

bool BinaryTree::isPerfect() const {
    if (root == nullptr) return true; // boş ağacı perfect sayıyoruz

    int d = leftmostLeafDepth(root);
    return isPerfectUtil(root, d, 0);
}

// ===============================
// Complete Binary Tree
// Level-order (BFS) ile kontrol
// ===============================
bool BinaryTree::isCompleteInternal() const {
    if (root == nullptr) return true;

    queue<Node*> q;
    q.push(root);
    bool nullSeen = false;

    while (!q.empty()) {
        Node* current = q.front();
        q.pop();

        if (current == nullptr) {
            nullSeen = true;
        } else {
            if (nullSeen) {
                // Daha önce null görmüştük ama sonradan düğüm çıktı → arada boşluk var
                return false;
            }
            q.push(current->left);
            q.push(current->right);
        }
    }
    return true;
}

bool BinaryTree::isComplete() const {
    return isCompleteInternal();
}

// ===============================
// Balanced Binary Tree
// ===============================
pair<bool,int> BinaryTree::checkBalanced(Node* node) const {
    if (node == nullptr) {
        return {true, -1};
    }

    auto leftInfo = checkBalanced(node->left);
    auto rightInfo = checkBalanced(node->right);

    bool balanced = leftInfo.first && rightInfo.first &&
                    abs(leftInfo.second - rightInfo.second) <= 1;

    int h = 1 + max(leftInfo.second, rightInfo.second);
    return {balanced, h};
}

bool BinaryTree::isBalanced() const {
    return checkBalanced(root).first;
}

// ===============================
// Degenerate Tree
// (Her iç düğümün tam 1 çocuğu var)
// ===============================
bool BinaryTree::isDegenerate(Node* node) const {
    if (node == nullptr) return true;

    bool hasLeft = (node->left != nullptr);
    bool hasRight = (node->right != nullptr);

    // Eğer iki çocuk varsa degenerate değil
    if (hasLeft && hasRight) {
        return false;
    }

    // Yapraksa sorun yok
    if (!hasLeft && !hasRight) {
        return true;
    }

    // Tek çocuk üzerinden devam
    if (hasLeft) {
        return isDegenerate(node->left);
    } else {
        return isDegenerate(node->right);
    }
}

bool BinaryTree::isDegenerate() const {
    return isDegenerate(root);
}

// ===============================
// Skewed Tree (Left / Right)
// ===============================
bool BinaryTree::isSkewedLeftRec(Node* node) const {
    if (node == nullptr) return true;

    // Sağ child varsa left-skewed olamaz
    if (node->right != nullptr) return false;

    // Ya yaprak, ya da sadece sol çocukla devam
    return isSkewedLeftRec(node->left);
}

bool BinaryTree::isSkewedRightRec(Node* node) const {
    if (node == nullptr) return true;

    // Sol child varsa right-skewed olamaz
    if (node->left != nullptr) return false;

    // Ya yaprak, ya da sadece sağ çocukla devam
    return isSkewedRightRec(node->right);
}

bool BinaryTree::isSkewedLeft() const {
    if (!isDegenerate()) return false;
    return isSkewedLeftRec(root);
}

bool BinaryTree::isSkewedRight() const {
    if (!isDegenerate()) return false;
    return isSkewedRightRec(root);
}

// ===============================
// Traversal
// ===============================
void BinaryTree::inorder(Node* node) const {
    if (node == nullptr) return;
    inorder(node->left);
    cout << node->data << " ";
    inorder(node->right);
}

void BinaryTree::printInorder() const {
    inorder(root);
    cout << endl;
}

// ===============================
// Bellek temizleme
// ===============================
void BinaryTree::freeTree(Node* node) {
    if (node == nullptr) return;
    freeTree(node->left);
    freeTree(node->right);
    delete node;
}
