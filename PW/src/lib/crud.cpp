#include <iostream>
// #include <BST.h>

#include <queue>

#include <node.h>
#include <func.h>


using namespace std;



//? Insertion =======================================================================

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

//? Search =======================================================================

node* DFSearch(struct node* root,int value){ // Depth First Search
    /*
        this function will return the node that has the value
    */

    if(!root) return nullptr;
    if(root->data == value) return root;

    if (value > root->data){
        return DFSearch(root->right,value);
    }else{
        return DFSearch(root->left,value);
    }
}


node* BFSearch(node* root,int value) { // Breadth First Search
    
    if (root == nullptr){
        return nullptr;
    }
    queue<node*> q;

    q.push(root);

    while (q.empty() == false ) {
        
        node* node = q.front();
        if (node->data == value){
            return node;
        }
        q.pop();

        if (node->left != nullptr){
            q.push(node->left);
        }

        if (node->right != nullptr){
            q.push(node->right);
        }
    }
    return nullptr;
}



node** __SearchNode(struct node* root, int value, node* prev = nullptr) {
    /*
        this function return the Node that has the value and the previous node
    */
    node** out = (node**)malloc(2*sizeof(node));

    if (root == nullptr || root->data == value) {
        out[0] = prev;
        out[1] = root;
        return out;
    }

    if (value > root->data) {
        return __SearchNode(root->right, value, root);
    } else {
        return __SearchNode(root->left, value, root);
    }
}


//?=======================================================================

int8_t* SearchMapNode(struct node* root,int value,int index = 0,int8_t* map = nullptr ){

    /*
        this function will return the path to the node that has the value
    */

    if (index == 0){
        map = (int8_t*)malloc(sizeof(int8_t)*100); // this wil use to show position of the elements
                                                    // 1->right ; -1->left ; 0->not_found ;2->the root
        if (!map){
            cout << "error in allocation of 'map'" << endl;
            return nullptr;
        }
    }

    if (root != NULL){

        if( value == root->data ){
            if(index == 0){
                map[index] = 2;
                map[index+1] = '\0';
            }
            return map;
        }
        else if( value < root->data ){
            if(root->left){
                map[index] = -1;
                SearchMapNode(root->left,value,index+1,map);
            }else{
                map[0] = 0;
                map[1] = '\0';
                return map;
            }
        }
        else{
            if(root->right){
                map[index] = 1;
                SearchMapNode(root->right,value,index+1,map);
            }else{
                map[0] = 0;
                map[1] = '\0';
                return map;
            }       
        }
    }

    return map;   
}

void SearchMapNode_p(struct node* root,int value){
    /*
        this function will print the path to the node that has the value
    */ 


    int index = 0;
    
    int8_t* map = SearchMapNode(root,value);
    
    if(!map[index]){
        cout << "not found" ; cout.flush();
    }
    
    while(map[index]){

        if(map[index] == 1){
            cout << "right" << " -> " ; cout.flush();
        }
        else if(map[index]==-1){
            cout << "left" << " -> " ; cout.flush();  
        }
        else if(map[index]==2){
            
            cout << "the root element" ; cout.flush();
            
        }else{
            cout << "not found" ; cout.flush();
        }

        index++;
    }
}
// ?==============================================================================


// ?Delete =======================================================================


struct node* DeleteNode(struct node* root, int value) {
    /*
        this function will delete the node that has the value
    */

    if (root == nullptr)
        return root;

    if (root->data > value)
        root->left = DeleteNode(root->left, value);
    else if (root->data < value)
        root->right = DeleteNode(root->right, value);

    else {
        if (root->left == nullptr) {
            struct node* temp = root->right;
            free(root);
            return temp;
        }

        if (root->right == nullptr) {
            struct node* temp = root->left;
            free(root);
            return temp;
        }

        struct node* succ = Successor(root);
        root->data = succ->data;
        root->right = DeleteNode(root->right, succ->data);
    }
    return root;
}




//? ==============================================================================
 