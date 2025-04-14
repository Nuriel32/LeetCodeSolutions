#include <iostream>
#include "BinarySearchTree.h"

using namespace std;

BinarySearchTree::BinarySearchTree() : root(nullptr) {}

BinarySearchTree::~BinarySearchTree() {
    destroy(root);
}

void BinarySearchTree::destroy(Node* node) {
    if (!node) return;
    destroy(node->left);
    destroy(node->right);
    delete node;
}

BinarySearchTree::Node* BinarySearchTree::insert(Node* node, int val) {
    if (!node) return new Node(val);

    if (val < node->value)
        node->left = insert(node->left, val);
    else if (val > node->value)
        node->right = insert(node->right, val);

    return node;
}

void BinarySearchTree::insert(int val) {
    root = insert(root, val);
}

bool BinarySearchTree::search(Node* node, int val) const {
    if (!node) return false;
    if (node->value == val) return true;
    if (val < node->value)
        return search(node->left, val);
    else
        return search(node->right, val);
}

bool BinarySearchTree::search(int val) const {
    return search(root, val);
}

void BinarySearchTree::inorder(Node* node) const {
    if (!node) return;
    inorder(node->left);
    cout << node->value << " ";
    inorder(node->right);
}

void BinarySearchTree::inorder() const {
    inorder(root);
    cout << endl;
}
