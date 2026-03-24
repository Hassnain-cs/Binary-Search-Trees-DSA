#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "bst.h"

int main() {
    Node* root = NULL;

    // Seed random generator
    srand((unsigned int)time(NULL));

    // Generate random number of chars (11 to 20)
    int numChars = rand() % 10 + 11;

    printf("Number of characters inserted: %d\n", numChars);

    printf("Inserted characters:\n");

    // Insert random lowercase letters
    for (int i = 0; i < numChars; i++) {
        char randomChar = 'a' + rand() % 26;
        printf("%c ", randomChar);

        root = insert(root, randomChar);
    }

    printf("\n\nSorted characters (Inorder Traversal):\n");
    inorderTraversal(root);

    printf("\n\nTotal Nodes: %d\n", countNodes(root));
    printf("Tree Height: %d\n", treeHeight(root));

    // Free memory
    freeTree(root);

    return 0;
}