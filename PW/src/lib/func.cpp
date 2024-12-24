#include <iostream>
#include <node.h>

using namespace std;


// struct node{
//     int data;
//     struct node *left;
//     struct node *right;   
// };



//? Successor ===================================================================
node* Successor(struct node* root ){

    if (!root || !root->right) return nullptr;
    node* selector = root->right;    

    while(selector->left){
        selector = selector->left;
    }
    return selector;
}

node* SuccessorRec(struct node* root,int8_t ft=1 ){ // ft: is the fisrt loop 

    if (!root || (!root->right && ft == 1) ) return nullptr;
    if (root->right && ft == 1) return SuccessorRec(root->right,0);
    if (!root->left && ft == 0) return root;
    
    return SuccessorRec(root->left,0);
}

node** __Successor(struct node* root ){

    /*
        this is a rectified Successor function to use it in delettion
    */

    if (!root || !root->right) return nullptr;
    node* prev = root;
    node* selector = root->right;  

    while(selector->left){
        prev = selector;
        selector = selector->left;
    }

    node** ptr = (node**)malloc(2*sizeof(node)) ;
    ptr[0] = prev;
    ptr[1] = selector;

    return ptr;
}


//? Predecessor ===================================================================
node* Predecessor(struct node* root ){

    if (!root || !root->left) return nullptr;
    node* selector = root->left;    

    while(selector->right){
        selector = selector->right;
    }
    return selector;
}

node* PredecessorRec(struct node* root,int8_t ft=1 ){ // ft: is the fisrt loop 

    if (!root || (!root->left && ft == 1) ) return nullptr;
    if (root->left && ft == 1) return PredecessorRec(root->left,0);
    if (!root->right && ft == 0) return root;
    
    return PredecessorRec(root->right,0);
}


node** __Predecessor(struct node* root ){

    /*
        this is a rectified Predecessor function to use it in delettion
    */

    if (!root || !root->left) return nullptr;
    node* prev = root;
    node* selector = root->left;    

    while(selector->right){
        prev = selector;
        selector = selector->right;
    }

    node** ptr = (node**)malloc(2*sizeof(node)) ;
    ptr[0] = prev;
    ptr[1] = selector;

    return ptr;
}



//? Traversal Methods ===============================================================

void InOrderTraversal(struct node* root){
    if(root != NULL) {
        InOrderTraversal(root->left);
        cout << root->data << " -> " ; cout.flush();
        InOrderTraversal(root->right);
    }
}

void PreOrderTraversal(struct node* root){
   if(root != NULL) {
        cout << root->data << " -> " ; cout.flush();
        PreOrderTraversal(root->left);
        PreOrderTraversal(root->right);
    }
} 

void PostOrderTraversal(struct node* root){
   if(root != NULL) {
        PostOrderTraversal(root->left);
        PostOrderTraversal(root->right);
        cout << root->data << " -> " ; cout.flush();
    }
} 