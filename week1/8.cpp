#include <iostream>

using namespace std;

class Node {
    public:
    int data;
    Node *left, *right;
    Node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

class BST {
    public:
    Node *root;
    BST() {
        root = NULL;
    }

    Node *insert(Node *node, int data) {
        if (node == NULL) {
            node = new Node(data);
            return node;
        }
        if (data <= node->data) {
            node->left = insert(node->left, data);
        }
        else {
            node->right = insert(node->right, data);
        }
        return node;        
    }

    void inOrder(Node *node) {
        if (node == NULL)
            return;
        inOrder(node->left);
        cout << node->data << " ";
        inOrder(node->right);
    }
};

int main() {
    BST *bst = new BST();
    bst->root = bst->insert(bst->root, 10);
    bst->root = bst->insert(bst->root, 8);
    bst->root = bst->insert(bst->root, 15);
    bst->root = bst->insert(bst->root, 14);
    bst->root = bst->insert(bst->root, 9);
    bst->root = bst->insert(bst->root, 7);
    bst->root = bst->insert(bst->root, 18);
    bst->root = bst->insert(bst->root, 13);
    bst->root = bst->insert(bst->root, 15);
    bst->root = bst->insert(bst->root, 11);
    bst->inOrder(bst->root);
    return 0;
}