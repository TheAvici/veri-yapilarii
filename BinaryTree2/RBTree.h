//
// Created by Sedo on 2.12.2025.
//

#ifndef BINARYTREE2_RBTREE_H
#define BINARYTREE2_RBTREE_H

enum Color { RED, BLACK };

struct RBNode {
    int key;
    Color color;
    RBNode* left;
    RBNode* right;
    RBNode* parent;

    RBNode(int k);
};

class RBTree {
public:
    RBTree();
    ~RBTree();

    RBTree(const RBTree&) = delete;
    RBTree& operator=(const RBTree&) = delete;

    void insert(int key);
    void printInorder() const;

private:
    RBNode* root;

    void leftRotate(RBNode* x);
    void rightRotate(RBNode* y);
    void fixInsert(RBNode* z);

    void inorderRec(RBNode* node) const;
    void freeTree(RBNode* node);
};

#endif //BINARYTREE2_RBTREE_H