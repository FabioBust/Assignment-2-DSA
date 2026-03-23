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