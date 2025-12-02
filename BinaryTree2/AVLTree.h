//
// Created by Sedo on 2.12.2025.
//

#ifndef BINARYTREE2_AVTTREE_H
#define BINARYTREE2_AVTTREE_H

// AVL düğümü
struct AVLNode {
    int key;
    int height;
    AVLNode* left;
    AVLNode* right;

    AVLNode(int k);
};

class AVLTree {
public:
    AVLTree();
    ~AVLTree();

    AVLTree(const AVLTree&) = delete;
    AVLTree& operator=(const AVLTree&) = delete;

    void insert(int key);
    void printInorder() const;

private:
    AVLNode* root;

    int getHeight(AVLNode* node) const;
    int getBalance(AVLNode* node) const;
    void updateHeight(AVLNode* node);

    AVLNode* rightRotate(AVLNode* y);
    AVLNode* leftRotate(AVLNode* y);

    AVLNode* insertRec(AVLNode* node, int key);
    void inorderRec(AVLNode* node) const;
    void freeTree(AVLNode* node);
};


#endif //BINARYTREE2_AVTTREE_H