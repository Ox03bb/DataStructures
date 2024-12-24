#include <iostream>
#include <node.h>

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

int8_t* DeleteNode(struct node* root,int value ){

    return 0;
}
