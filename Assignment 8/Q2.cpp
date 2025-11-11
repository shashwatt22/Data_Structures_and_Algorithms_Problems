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

Node* searchRec(Node* root, int key) {
    if (!root || root->data == key) return root;
    if (key < root->data) return searchRec(root->left, key);
    return searchRec(root->right, key);
}

Node* searchNonRec(Node* root, int key) {
    while (root) {
        if (root->data == key) return root;
        root = key < root->data ? root->left : root->right;
    }
    return NULL;
}

Node* minNode(Node* root) {
    while (root && root->left) root = root->left;
    return root;
}

Node* maxNode(Node* root) {
    while (root && root->right) root = root->right;
    return root;
}

Node* inorderSuccessor(Node* root, Node* x) {
    Node* succ = NULL;
    while (root) {
        if (x->data < root->data) {
            succ = root;
            root = root->left;
        } else root = root->right;
    }
    return succ;
}

Node* inorderPredecessor(Node* root, Node* x) {
    Node* pred = NULL;
    while (root) {
        if (x->data > root->data) {
            pred = root;
            root = root->right;
        } else root = root->left;
    }
    return pred;
}

int main() {
    Node* root = NULL;
    root = insert(root, 10);
    insert(root, 5);
    insert(root, 15);
    insert(root, 2);
    insert(root, 7);
    Node* x = searchRec(root, 5);
    cout << "Search (Rec): " << (x ? "Found" : "Not Found") << endl;
    cout << "Min: " << minNode(root)->data << endl;
    cout << "Max: " << maxNode(root)->data << endl;
    cout << "Successor of 5: " << inorderSuccessor(root, x)->data << endl;
    cout << "Predecessor of 5: " << inorderPredecessor(root, x)->data << endl;
}
