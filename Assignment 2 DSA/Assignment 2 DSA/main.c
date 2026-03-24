#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "tree.h"

int main() {
    Node* root = NULL;

    // Seed random number generator with current time
    srand(time(NULL));

    // Random number of chars (11–20)
    int numChars = rand() % 10 + 11;

    printf("Inserted characters:\n");

    for (int i = 0; i < numChars; i++) {
        char c = 'a' + rand() % 26; // Generate a random lowercase letter
        printf("%c ", c);
        root = insert(root, c); // Insert the character into the BST
    }

    printf("\n\nSorted (In-Order Traversal):\n");
    printTree(root);    // Print all nodes in sorted order

    printf("\n\nNumber of Nodes: %d\n", countNodes(root));  // Count and display nodes
    printf("Tree Height: %d\n", treeHeight(root));  // Calculate and display tree height

    // Search for a random character in the tree
    char target = 'a' + rand() % 26;
    printf("\n\nSearching for: %c\n", target);

    Node* result = search(root, target); // Call search function

    // Check if the character was found
    if (result != NULL) {
        printf("Character %c found in the tree.\n", target);
    }
    else {
        printf("Character %c not found in the tree.\n", target);
    }

    return 0;
}