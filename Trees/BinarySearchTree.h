#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

class BinarySearchTree {
private:
    struct Node {
        int value;
        Node* left;
        Node* right;

        Node(int val) : value(val), left(nullptr), right(nullptr) {}
    };

    Node* root;

    // פונקציות עזר רקורסיביות
    Node* insert(Node* node, int val);
    bool search(Node* node, int val) const;
    void inorder(Node* node) const;
    void destroy(Node* node);

public:
    BinarySearchTree();
    ~BinarySearchTree();

    void insert(int val);
    bool search(int val) const;
    void inorder() const;
};

#endif
