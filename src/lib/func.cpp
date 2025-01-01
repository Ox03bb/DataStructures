#include <iostream>
#include <node.h>
// #include <BST.h>

#include <vector>
#include <queue>

using namespace std;



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
        this is a retun the successor and the previous node of the successor
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
        this function will return the predecessor and the previous node of the predecessor
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


//? BST to Array ====================================================================


void ToArray(node* root, vector<int>& array) {
    if (root != NULL) {
        ToArray(root->left, array);  // Traverse the left subtree
        array.push_back(root->data); // Add current node's data
        ToArray(root->right, array); // Traverse the right subtree
    }
}

vector<int> ToArray(node* root) {
    vector<int> array;
    ToArray(root, array);
    return array;
}

//? MaxDepth of BST ====================================================================

int MaxDepth(node* root) {
    if (root == nullptr) {
        return 0;
    } else {
        int leftDepth = MaxDepth(root->left);
        int rightDepth = MaxDepth(root->right);

        return max(leftDepth, rightDepth) + 1;
    }
}

//? menu ====================================================================

void menu(){
    cout << "\n1. Insert Node" << endl;
    cout << "2. Delete Node" << endl;
    cout << "3. Search Node" << endl;
    cout << "4. InOrder Traversal" << endl;
    cout << "5. PreOrder Traversal" << endl;
    cout << "6. PostOrder Traversal" << endl;
    cout << "7. Max Depth" << endl;
    cout << "0. Exit" << endl;
    cout << "Enter your choice: ";
}