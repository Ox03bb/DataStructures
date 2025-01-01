#ifndef BST_CRUD_H
#define BST_CRUD_H

#include <iostream>
#include <node.h>


using namespace std;

// Insertion
void InsertNode(node *root, int value);

// Search
node* DFSearch(struct node* root, int value);
node* BFSearch(node* root,int value); // Breadth First Search

int8_t* SearchMapNode(struct node* root, int value, int index = 0, int8_t* map = nullptr);
void SearchMapNode_p(struct node* root, int value);

// Delete
int8_t* DeleteNode(struct node* root, int value);

#endif