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

bool isBSTUtil(Node* root, int min, int max) {
    if (!root) return true;
    if (root->data <= min || root->data >= max) return false;
    return isBSTUtil(root->left, min, root->data) &&
           isBSTUtil(root->right, root->data, max);
}

bool isBST(Node* root) {
    return isBSTUtil(root, -100000, 100000);
}

int main() {
    Node* root = newNode(10);
    root->left = newNode(5);
    root->right = newNode(20);
    cout << (isBST(root) ? "BST" : "Not BST");
}
