#include <iostream>
// #include <BST.h>
#include <node.h>
#include <func.h>


using namespace std;


// struct node{
//     int data;
//     struct node *left;
//     struct node *right;   
// };


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

node* SearchNode(struct node* root,int value){
    if(!root) return nullptr;
    if(root->data == value) return root;

    if (value > root->data){
        return SearchNode(root->right,value);
    }else{
        return SearchNode(root->left,value);
    }
}


node** __SearchNode(struct node* root, int value, node* prev = nullptr) {
    /*
    this function well use in delete
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

// int8_t DeleteNode(struct node* root,int value ){

//     node** TrSuc = (node**)malloc(sizeof(node*));
//     node* Suc = (node*)malloc(sizeof(node));
//     node* SucPrev = (node*)malloc(sizeof(node));
//     node** TargetPtr = __SearchNode(root,value);

    
//     if (!TargetPtr[1]) return 0 ;

//     node* Target_prev = TargetPtr[0];
//     node* Target = TargetPtr[1]; 
//     free(TargetPtr);

   


//     int8_t SucOrPre = 0;

//     if (Target){
//         TrSuc = __Successor(Target);

//         if (TrSuc[1]==nullptr){

//             SucOrPre = 1;
//             TrSuc = __Predecessor(Target);
//         }

//         SucPrev = TrSuc[0];
//         Suc = TrSuc[1];
//         free(TrSuc);

//     }else{
//         return 0;
//     }

//     if (!Target_prev){ // meas that we 'll del the global root
//         Suc = root;
        
//         Suc->right = Target->right;
//         Suc->left = Target->left;
//         cout << Suc << "||" << Suc->left->data << "||" << root->right <<endl;
        
//         if(SucOrPre == 0 ){
//             SucPrev->left = nullptr;

//         }else{
//             SucPrev->right = nullptr;

//         }

//     }

//     free(Target);

//     return 1;
// }


struct node* DeleteNode(struct node* root, int value) {
    cout << "DeleteNode" << endl;

    if (root == nullptr)
        return root;

    // If key to be searched is in a subtree
    if (root->data > value)
        root->left = DeleteNode(root->left, value);
    else if (root->data < value)
        root->right = DeleteNode(root->right, value);

    // If root matches with the given key
    else {
        // Cases when root has 0 children or only right child
        if (root->left == nullptr) {
            struct node* temp = root->right;
            free(root);
            return temp;
        }

        // When root has only left child
        if (root->right == nullptr) {
            struct node* temp = root->left;
            free(root);
            return temp;
        }

        // When both children are present
        struct node* succ = Successor(root);
        root->data = succ->data;
        root->right = DeleteNode(root->right, succ->data);
    }
    return root;
}




//? ==============================================================================
