#include "AVL.h"
#include <iostream>
#include <algorithm>
using namespace std;

int getHeight(Node* node) {
    if (node == nullptr) return 0;
    return node->height;
}

int getBalanceFactor(Node* node) {
    if (node == nullptr) return 0;
    // positive = left-heavy, negative = right-heavy
    return getHeight(node->left) - getHeight(node->right);
}

void updateHeight(Node* node) {
    if (node == nullptr) return;
    // height = 1 (current node) + tallest child
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));
}

// LL case: right-rotate around y
Node* rotateRight(Node* y) {
    Node* x  = y->left;
    Node* T2 = x->right;
    x->right = y;
    y->left  = T2;
    updateHeight(y);
    updateHeight(x);
    return x;
}

// RR case: left-rotate around x
Node* rotateLeft(Node* x) {
    Node* y  = x->right;
    Node* T2 = y->left;
    y->left  = x;
    x->right = T2;
    updateHeight(x);
    updateHeight(y);
    return y;
}

// check balance factor and apply the correct rotation
Node* rebalance(Node* n) {
    updateHeight(n);
    int balance = getBalanceFactor(n);

    // left-heavy (bf > 1)
    if (balance > 1 && getBalanceFactor(n->left) >= 0) {
        return rotateRight(n);              // LL
    }
    if (balance > 1 && getBalanceFactor(n->left) < 0) {
        n->left = rotateLeft(n->left);      // LR
        return rotateRight(n);
    }

    // right-heavy (bf < -1)
    if (balance < -1 && getBalanceFactor(n->right) <= 0) {
        return rotateLeft(n);               // RR
    }
    if (balance < -1 && getBalanceFactor(n->right) > 0) {
        n->right = rotateRight(n->right);   // RL
        return rotateLeft(n);
    }

    return n; // already balanced
}

Node* insertAVL(Node* root, int data) {
    // step 1: insert like a normal BST
    if (root == nullptr) return createNode(data);
    if (data < root->data) {
        root->left  = insertAVL(root->left,  data);
    } else if (data > root->data) {
        root->right = insertAVL(root->right, data);
    }
    // duplicate: do nothing

    // step 2: rebalance on the way back up
    return rebalance(root);
}

Node* deleteAVL(Node* root, int data) {
    // step 1: delete like a normal BST
    if (root == nullptr) return nullptr;
    if (data < root->data) {
        root->left  = deleteAVL(root->left,  data);
    } else if (data > root->data) {
        root->right = deleteAVL(root->right, data);
    } else {
        // node found — handle 3 cases
        if (root->left == nullptr) {
            // case 1 & 2: no left child — promote right child
            Node* t = root->right;
            delete root;
            return t;
        } else if (root->right == nullptr) {
            // case 2: no right child — promote left child
            Node* t = root->left;
            delete root;
            return t;
        } else {
            // case 3: two children — replace with in-order successor
            Node* successor = root->right;
            while (successor->left != nullptr) {
                successor = successor->left; // go as far left as possible
            }
            root->data  = successor->data;                        // copy successor's data up
            root->right = deleteAVL(root->right, successor->data); // delete successor
        }
    }

    // step 2: rebalance on the way back up
    return rebalance(root);
}