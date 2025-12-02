#include <iostream>
#include "BinaryTree.h"
#include "Node.h"

using namespace std;

// Perfect / Full / Complete örneği:
//        4
//      /   \
//     2     6
//    / \   / \
//   1   3 5   7
void buildPerfectTree(BinaryTree& t) {
    Node* r = new Node(4);
    r->left = new Node(2);
    r->right = new Node(6);
    r->left->left = new Node(1);
    r->left->right = new Node(3);
    r->right->left = new Node(5);
    r->right->right = new Node(7);

    t.setRoot(r);
}

// Sola eğik (left-skewed) degenerate ağaç
// 4
// /
// 3
// /
// 2
// /
// 1
void buildLeftSkewedTree(BinaryTree& t) {
    Node* r = new Node(4);
    r->left = new Node(3);
    r->left->left = new Node(2);
    r->left->left->left = new Node(1);

    t.setRoot(r);
}

// Improper / not full / not perfect bir ağaç
//    10
//   /
//  5
//   \
//    7
void buildImproperTree(BinaryTree& t) {
    Node* r = new Node(10);
    r->left = new Node(5);
    r->left->right = new Node(7); // tek çocuklu düğüm var

    t.setRoot(r);
}

void printTreeInfo(const string& name, const BinaryTree& t) {
    cout << "=== " << name << " ===\n";
    cout << "Inorder: ";
    t.printInorder();
    cout << "isProper       : " << t.isProper()      << endl;
    cout << "isFull         : " << t.isFull()        << endl;
    cout << "isComplete     : " << t.isComplete()    << endl;
    cout << "isBalanced     : " << t.isBalanced()    << endl;
    cout << "isDegenerate   : " << t.isDegenerate()  << endl;
    cout << "isSkewedLeft   : " << t.isSkewedLeft()  << endl;
    cout << "isSkewedRight  : " << t.isSkewedRight() << endl;
    cout << "isPerfect      : " << t.isPerfect()     << endl;
    cout << "----------------------------------------\n\n";
}

int main() {
    cout << boolalpha; // true/false yazsın diye

    BinaryTree perfectTree;
    buildPerfectTree(perfectTree);

    BinaryTree leftSkewed;
    buildLeftSkewedTree(leftSkewed);

    BinaryTree improperTree;
    buildImproperTree(improperTree);

    printTreeInfo("Perfect / Full / Complete Ornek", perfectTree);
    printTreeInfo("Left-Skewed (Degenerate) Ornek", leftSkewed);
    printTreeInfo("Improper Ornek (tek cocuklu dugum var)", improperTree);

    return 0;
}
