#ifndef BST_FUNC_H
#define BST_FUNC_H

#include <iostream>
#include <node.h>


using namespace std;

// struct node {
//     int data;
//     struct node *left;
//     struct node *right;   
// };

// Successor functions
node* Successor(struct node* root);
node* SuccessorRec(struct node* root, int8_t ft = 1);
node** __Successor(struct node* root);

// Predecessor functions
node* Predecessor(struct node* root);
node* PredecessorRec(struct node* root, int8_t ft = 1);
node** __Predecessor(struct node* root);

// Traversal methods
void InOrderTraversal(struct node* root);
void PreOrderTraversal(struct node* root);
void PostOrderTraversal(struct node* root);

#endif 