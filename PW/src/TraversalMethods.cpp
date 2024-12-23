#include <iostream>
#include <node.cpp>

using namespace std;




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