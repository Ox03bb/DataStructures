#include <iostream>

using namespace std;




struct node{
    int data;
    struct node *left;
    struct node *right;   
};


// ! CRUD

void InsertNode(node *root,int value){
    if (root == nullptr) {
        return;
    }

    if (!root->data || root->data == value){
    
        root->data = value;
    
    }else{
        
        node *nd = (node*)malloc(sizeof(node)); 
        nd->data = value;
        nd->right = nullptr;
        nd->left = nullptr;


        if( value > root->data){
            if (!root->right){

                root->right = nd;

            }else{

                InsertNode(root->right,value);            
            }
        }else{
            if (!root->left){

                node *nd = (node*)malloc(sizeof(node));

                nd->data = value;
                nd->right = nullptr;
                nd->left = nullptr;

                root->left = nd;

            }else{

                InsertNode(root->left,value);
            
            }
        }
    }
}


int8_t SearchNode(struct node* root,int value){
    if (root != NULL){
        if( value == root->data ){
           return 1;
        }
        else if( value < root->data ){
            SearchNode(root->left,value);
        }
        else{
            SearchNode(root->right,value);
        }
    }
    return 0;
}


//! Tree Traversal Methods 

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




int main(){
    node *tree = (node*)malloc(sizeof(node));

    InsertNode(tree,5);
    InsertNode(tree,1);
    InsertNode(tree,7);
    InsertNode(tree,2);
    InsertNode(tree,0);

    int8_t a = SearchNode(tree,1);

    cout << "search : " << (int)a << endl;
    printf("%d",a);

    return 1;
}

