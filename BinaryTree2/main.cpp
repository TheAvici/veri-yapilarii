#include <iostream>
#include "BST.h"
#include "AVLTree.h"
#include "RBTree.h"

using namespace std;

int main() {
    cout << "=== BST Ornegi ===\n";
    BST bst;
    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);
    bst.insert(60);
    bst.insert(80);
    cout << "BST inorder        : ";
    bst.printInorder();
    cout << "BST search 40      : " << (bst.search(40) ? "bulundu" : "yok") << "\n\n";

    cout << "=== AVL Ornegi ===\n";
    AVLTree avl;
    avl.insert(10);
    avl.insert(20);
    avl.insert(30);
    avl.insert(40);
    avl.insert(50);
    avl.insert(25);
    cout << "AVL inorder key(h) : ";
    avl.printInorder();
    cout << "\n\n";

    cout << "=== Red-Black Tree Ornegi ===\n";
    RBTree rbt;
    rbt.insert(10);
    rbt.insert(20);
    rbt.insert(30);
    rbt.insert(15);
    rbt.insert(25);
    rbt.insert(5);
    cout << "RBTree inorder k(C): ";
    rbt.printInorder();
    cout << "\n";

    return 0;
}
