#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

// Helper function to create a new node
Node* createNode(char value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

// Insert function (recursive)
Node* insert(Node* root, char value) {
    // If tree is empty, create a new node
    if (root == NULL) {
        return createNode(value);
    }

    // Insert into left subtree
    if (value < root->data) {
        root->left = insert(root->left, value);
    }
    // Insert into right subtree
    else if (value > root->data) {
        root->right = insert(root->right, value);
    }

    // If equal, do nothing (avoid duplicates)
    return root;
}

// Search function
int search(Node* root, char value) {
    if (root == NULL)
        return 0;

    if (root->data == value)
        return 1;

    if (value < root->data)
        return search(root->left, value);
    else
        return search(root->right, value);
}

// Count nodes
int countNodes(Node* root) {
    if (root == NULL)
        return 0;

    return 1 + countNodes(root->left) + countNodes(root->right);
}

// Calculate tree height
int treeHeight(Node* root) {
    if (root == NULL)
        return -1; // Important: height of empty tree

    int leftHeight = treeHeight(root->left);
    int rightHeight = treeHeight(root->right);

    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

// Inorder traversal (sorted output)
void inorderTraversal(Node* root) {
    if (root == NULL)
        return;

    inorderTraversal(root->left);
    printf("%c ", root->data);
    inorderTraversal(root->right);
}

// Free memory
void freeTree(Node* root) {
    if (root == NULL)
        return;

    freeTree(root->left);
    freeTree(root->right);
    free(root);
}