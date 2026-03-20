#pragma once
#include "BST.h"

// Helper functions
int  getHeight(Node* node);
int  getBalanceFactor(Node* node);
void updateHeight(Node* node);

// AVL rotations
Node* rotateRight(Node* y);
Node* rotateLeft(Node* x);

// Rebalance the node if it has become unbalanced
Node* rebalance(Node* node);

// AVL operations
Node* insertAVL(Node* root, int key);
Node* deleteAVL(Node* root, int key);