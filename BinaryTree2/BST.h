//
// Created by Sedo on 2.12.2025.
//

#ifndef BINARYTREE2_BST_H
#define BINARYTREE2_BST_H


// Basit Binary Search Tree düğümü
struct BSTNode {
    int key;
    BSTNode* left;
    BSTNode* right;

    BSTNode(int k);
};

class BST {
public:
    BST();
    ~BST();

    // Kopyalamayı yasaklıyoruz (double free riskine girmemek için)
    BST(const BST&) = delete;
    BST& operator=(const BST&) = delete;

    void insert(int key);
    bool search(int key) const;
    void printInorder() const;

private:
    BSTNode* root;

    BSTNode* insertRec(BSTNode* node, int key);
    bool searchRec(BSTNode* node, int key) const;
    void inorderRec(BSTNode* node) const;
    void freeTree(BSTNode* node);
};

#endif //BINARYTREE2_BST_H