#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

// Create new node
Node* createNode(char data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Insert a character into the BST
Node* insert(Node* root, char data) {
    
    // Empty tree/subtree
    if (root == NULL) {                            
        return createNode(data); // Create new node here
    }
    
    // Smaller values go left
    if (data < root->data) {                       
        root->left = insert(root->left, data); // Recur left
    }
    
    // Larger values go right
    else if (data > root->data) {                  
        root->right = insert(root->right, data); // Recur right
    }

    return root; // Return the unchanged root
}

// Search for a character in the BST
Node* search(Node* root, char data) {
    
    // Base case: not found or match
    if (root == NULL || root->data == data) {      
        return root;
    }
    
    // If smaller, search left subtree
    if (data < root->data) {                       
        return search(root->left, data);
    }
   
    // If larger, search right subtree
    else {                                         
        return search(root->right, data);
    }
}

// Count the total number of nodes in the BST
int countNodes(Node* root) {
    
    // empty subtree
    if (root == NULL) {           
        return 0;
    }

    // Count current node + nodes in left and right subtrees
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// Find the height of the BST
int treeHeight(Node* root) {

    // empty tree has height -1
    if (root == NULL) {
        return -1;
    }

    // Recursively find height of left and right subtrees
    int leftHeight = treeHeight(root->left);
    int rightHeight = treeHeight(root->right);

    // Height is max of left/right + 1 for current node
    if (leftHeight > rightHeight) {
        return leftHeight + 1;
    }
    else {
        return rightHeight + 1;
    }
}

// Print all nodes in alphabetical order (in-order traversal)
void printTree(Node* root) {
    if (root != NULL) {
        printTree(root->left);    // Visit left subtree first
        printf("%c ", root->data);   // Then current node
        printTree(root->right);   // Finally, right subtree
    }
}