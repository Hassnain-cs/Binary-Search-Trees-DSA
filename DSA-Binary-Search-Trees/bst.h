#ifndef BST_H
#define BST_H

// Structure for a single node in BST
typedef struct Node {
    char data;
    struct Node* left;
    struct Node* right;
} Node;

// Function declarations

// Insert a character into the BST
Node* insert(Node* root, char value);

// Search for a character in BST
int search(Node* root, char value);

// Count total nodes
int countNodes(Node* root);

// Calculate height of tree
int treeHeight(Node* root);

// Print tree in sorted order (inorder traversal)
void inorderTraversal(Node* root);

// Free allocated memory
void freeTree(Node* root);

#endif