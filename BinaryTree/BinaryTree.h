//
// Created by Sedo on 2.12.2025.
//

#ifndef BINARYTREE_BINARYTREE_H
#define BINARYTREE_BINARYTREE_H


#include "Node.h"
#include <utility>   // std::pair

class BinaryTree {
public:
    BinaryTree();
    ~BinaryTree();

    // Kopyalamayı yasaklıyoruz (double free olmasın diye)
    BinaryTree(const BinaryTree&) = delete;
    BinaryTree& operator=(const BinaryTree&) = delete;

    // Dışarıdan root atamak için (örnek ağaç kurarken kullanacağız)
    void setRoot(Node* node);
    Node* getRoot() const;

    // Özellik kontrolleri
    bool isProper() const;        // strict/proper: 0 veya 2 çocuk
    bool isFull() const;          // full binary tree (proper ile aynı mantık)
    bool isComplete() const;      // complete binary tree
    bool isBalanced() const;      // balanced binary tree
    bool isDegenerate() const;    // degenerate tree
    bool isSkewedLeft() const;    // sadece sola eğik
    bool isSkewedRight() const;   // sadece sağa eğik
    bool isPerfect() const;       // perfect binary tree

    // Traversal
    void printInorder() const;

private:
    Node* root;

    // Yardımcı fonksiyonlar (private)
    bool isProper(Node* node) const;
    int height(Node* node) const;

    int leftmostLeafDepth(Node* node) const;
    bool isPerfectUtil(Node* node, int expectedDepth, int level) const;

    bool isCompleteInternal() const;

    std::pair<bool,int> checkBalanced(Node* node) const;

    bool isDegenerate(Node* node) const;

    bool isSkewedLeftRec(Node* node) const;
    bool isSkewedRightRec(Node* node) const;

    void inorder(Node* node) const;
    void freeTree(Node* node);
};


#endif //BINARYTREE_BINARYTREE_H