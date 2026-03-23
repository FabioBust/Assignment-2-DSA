#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "tree.h"

int main() {
    Node* root;

    srand(time(NULL));

    // Random number of chars (11–20)
    int numChars = rand() % 10 + 11;

    printf("Inserted characters:\n");

    for (int i = 0; i < numChars; i++) {
        char c = rand() % 26 + 'a';
        printf("%c ", c);
        root = insert(root, c);
    }

    printf("\n\nSorted (In-Order Traversal):\n");
    printTree(root);

    printf("\n\nNumber of Nodes: %d\n", countNodes(root));
    printf("Tree Height: %d\n", treeHeight(root));

    return 0;
}

