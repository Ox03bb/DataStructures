#ifndef BST_CRUD_H
#define BST_CRUD_H

#include <iostream>
#include <BST.h>


using namespace std;

// struct node{
//     int data;
//     struct node *left;
//     struct node *right;   
// };


// Insertion
void InsertNode(node *root, int value);

// Search
node* SearchNode(struct node* root, int value);
int8_t* SearchMapNode(struct node* root, int value, int index = 0, int8_t* map = nullptr);
void SearchMapNode_p(struct node* root, int value);

// Delete
int8_t* DeleteNode(struct node* root, int value);

#endif