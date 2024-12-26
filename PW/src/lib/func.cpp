#include <iostream>
#include <node.h>
// #include <BST.h>

#include <vector>
#include <queue>

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

//? Visualization=============================================================================



void Visualization(node* root) {
    if (root == nullptr) {
        cout << "Error: Tree is empty." << endl;
        return;
    }

    queue<pair<node*, int>> q; // Pair to store node and its level
    q.push({root, 0});

    int currentLevel = 0;

    while (!q.empty()) {
        node* currentNode = q.front().first;
        int level = q.front().second;
        q.pop();

        // Print a new line when moving to the next level
        if (level > currentLevel) {
            cout << endl;
            currentLevel = level;
        }

        // Print the current node's value
        cout << currentNode->data << " ";

        // Add children to the queue with their level
        if (currentNode->left != nullptr) {
            q.push({currentNode->left, level + 1});
        }

        if (currentNode->right != nullptr) {
            q.push({currentNode->right, level + 1});
        }
    }
    cout << endl;
}


// void Visualization(node* tree) {
//     int root_val = tree->data;
//     vector<int> array = ToArray(tree);

//     cout << root->data << 

//     for (int element : array) {
    
    
//         cout << element << " -> " ;
//     }
// }

//? =================================================================================


//? BST Visualization ===============================================================

// void Visualization(node* tree){

//     // node* 
//     vector<int> array;
//     array = ToArray(tree, array);

//     // vector<int> array = ToArray(tree);
//     // int index = 0;


//     for (int elemnt : array) {
//         cout << elemnt << " -> " << endl;
//     }

//     // while(array[index]){
//     //     cout << (int)array[index] << " -> " << endl;
//     //     index ++;
//     // }
// }