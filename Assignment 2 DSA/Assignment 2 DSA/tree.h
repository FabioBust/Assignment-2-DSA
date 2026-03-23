#ifndef TREE_H
#define TREE_H

// Define structure of a tree Node
typedef struct Node {
    char data;
    struct Node* left;  // Pointer to left child
    struct Node* right; // Pointer to right child
} Node;

// Function declarations
Node* insert(Node* root, char data);
Node* search(Node* root, char data);
int countNodes(Node* root);
int treeHeight(Node* root);
void printTree(Node* root);

#endif