#pragma once
#include "Node.h"
#include<iostream>
using namespace std;

Node* createNode(int x);

// BST operations
Node* Insert(Node* root, int x);
Node* Delete(Node* root, int x);
Node* Search(Node* root, int x);

// 4 Traversals
void preOrder(Node* root);
void inOrder(Node* root);
void postOrder(Node* root);
void levelOrder(Node* root);

// Utility functions
int Height(Node* root);
int sizeOf(Node* root);
int isEmpty(Node* root);

// Helper function
bool isLeafNode(Node* l);
Node* findMin(Node* root);