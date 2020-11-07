#include <iostream>

using namespace std;

class Node {
    public:
    int data;
    Node *left, *right;

    Node(int data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

class BST {
    public:
    Node *root;
    int triangle_cnt;
    BST() {
        root = NULL;
        triangle_cnt = 0;
    }

    Node *insert(Node *node, int data) {
        if (node == NULL) {
            node = new Node(data);
            return node;
        }

        if (data <= node->data) 
            node->left = insert(node->left, data);
        else
            node->right = insert(node->right, data);

        return node;
    }

    void inOrder(Node *node) {
        
        if (node == NULL)
            return;
        if (node->left != NULL && node->right != NULL)
            triangle_cnt++;
        inOrder(node->left);
        // cout << node->data << " ";
        inOrder(node->right);
    }

    Node *findMin(Node *node) {
        while (node->left != NULL)
            node = node->left;
        return node;
    }

    Node *findMax(Node *node) {
        while (node->right != NULL)
            node = node->right;
        return node;
    }

    Node *deleteNode(Node *node, int data) {
        if (node == NULL)
            return NULL;
        if (data < node->data)
            node->left = deleteNode(node->left, data);
        else if (data > node->data)
            node->right = deleteNode(node->right, data);
        else {
            if (node->right == NULL && node->left == NULL)
                node = NULL;
            else if (node->left == NULL)
                node = node->right;
            else if (node->right == NULL)
                node = node->left;
            else {
                Node *tmp = findMax(node->left);
                node->data = tmp->data;
                node->left = deleteNode(node->left, tmp->data);
            }
        }
    }
};

int main() {
    BST *bst = new BST();
    int n, x;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        bst->root = bst->insert(bst->root, x);
    }
    bst->inOrder(bst->root);
    cout << bst->triangle_cnt;
    return 0;
}