#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
};

Node* newNode(int x) {
    Node* n = new Node;
    n->data = x;
    n->left = n->right = NULL;
    return n;
}

Node* insert(Node* root, int x) {
    if (!root) return newNode(x);
    if (x < root->data) root->left = insert(root->left, x);
    else if (x > root->data) root->right = insert(root->right, x);
    return root;
}

Node* minNode(Node* root) {
    while (root->left) root = root->left;
    return root;
}

Node* deleteNode(Node* root, int key) {
    if (!root) return root;
    if (key < root->data) root->left = deleteNode(root->left, key);
    else if (key > root->data) root->right = deleteNode(root->right, key);
    else {
        if (!root->left) {
            Node* t = root->right;
            delete root;
            return t;
        } else if (!root->right) {
            Node* t = root->left;
            delete root;
            return t;
        }
        Node* t = minNode(root->right);
        root->data = t->data;
        root->right = deleteNode(root->right, t->data);
    }
    return root;
}

int maxDepth(Node* root) {
    if (!root) return 0;
    int l = maxDepth(root->left);
    int r = maxDepth(root->right);
    return (l > r ? l : r) + 1;
}

int minDepth(Node* root) {
    if (!root) return 0;
    int l = minDepth(root->left);
    int r = minDepth(root->right);
    return (l < r ? l : r) + 1;
}

void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    Node* root = NULL;
    root = insert(root, 10);
    insert(root, 5);
    insert(root, 15);
    insert(root, 2);
    insert(root, 7);
    inorder(root);
    cout << "\nAfter delete 5:\n";
    root = deleteNode(root, 5);
    inorder(root);
    cout << "\nMax Depth: " << maxDepth(root);
    cout << "\nMin Depth: " << minDepth(root);
}
