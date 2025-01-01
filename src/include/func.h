#ifndef BST_FUNC_H
#define BST_FUNC_H

#include <iostream>
#include <node.h>
#include <vector>

using namespace std;

// Successor functions
node* Successor(struct node* root);
node* SuccessorRec(struct node* root,int8_t ft = 1);
node** __Successor(struct node* root);

// Predecessor functions
node* Predecessor(struct node* root);
node* PredecessorRec(struct node* root, int8_t ft = 1);
node** __Predecessor(struct node* root);

// Traversal methods
void InOrderTraversal(struct node* root);
void PreOrderTraversal(struct node* root);
void PostOrderTraversal(struct node* root);


vector<int> ToArray(node* root);
int MaxDepth(node* root) ;


void menu();

#endif 