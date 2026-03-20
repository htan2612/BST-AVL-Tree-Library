#include "Node.h"
#include "BST.h"
#include<iostream>
#include<vector>
using namespace std;

Node* createNode(int x) {
    Node* temp = new Node();
    temp->data = x;
    temp->left = nullptr;
    temp->right = nullptr;
    temp->height = 1;
    return temp;
}

Node* Insert(Node* root, int x) {
    if (root == nullptr) return createNode(x);
    if (x < root->data) {
        root->left  = Insert(root->left,  x);
    }
    else if (x > root->data) {
        root->right = Insert(root->right, x);
    }
    return root;
}

Node* findMin(Node* root) {
    if (root == nullptr) return nullptr;
    if (root->left == nullptr) return root;
    return findMin(root->left);
}

Node* Delete(Node* root, int x) {
    if (root == nullptr) return root;

    if (x < root->data) {
        root->left = Delete(root->left, x);
    }
    else if (x > root->data) {
        root->right = Delete(root->right, x);
    }
    else {
        // case 1 & 2: node has at most one child
        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // case 3: node has two children
        // find in-order successor (smallest node in right subtree)
        Node* temp = root->right;
        while (temp && temp->left != nullptr) {
            temp = temp->left;
        }

        // copy successor's key up, then delete the successor
        root->data = temp->data;
        root->right = Delete(root->right, temp->data);
    }

    return root;
}

Node* Search(Node* root, int x) {
    if (root == nullptr) return nullptr;
    if (x == root->data) return root;
    if (x < root->data) return Search(root->left, x);
    return Search(root->right, x);
}

void preOrder(Node* root){
	if (root != nullptr){
		cout << root->data << " " ;
		preOrder(root->left);
		preOrder(root->right);
	}
}

void inOrder(Node* root){
    if (root != nullptr){
        inOrder(root->left);
        cout << root->data << " " ;
        inOrder(root->right);
    }
}

void postOrder(Node* root){
    if (root != nullptr) {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->data << " " ;
    }
}

void levelOrder(Node* root) {
    if (root == nullptr) return;
    vector<Node*> q;
    q.push_back(root);
    int i = 0;
    while (i < (int)q.size()) {
        Node* current = q[i++];
        cout << current->data << " ";
        if (current->left)  q.push_back(current->left);
        if (current->right) q.push_back(current->right);
    }
}

bool isLeafNode(Node* l){
	return (l->left == nullptr && l->right == nullptr);
}

int Height(Node* root) {
    if (root == nullptr) return 0;
    return 1 + max(Height(root->left), Height(root->right));
}

int sizeOf(Node* root) {
    if (root == nullptr) return 0;
    return 1 + sizeOf(root->left) + sizeOf(root->right);
}

int isEmpty(Node* root) {
    return root == nullptr;
}