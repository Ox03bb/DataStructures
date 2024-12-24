#include <iostream>

using namespace std;

struct node{
    int data;
    struct node *left;
    struct node *right;   
};


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

int8_t* SearchNode(struct node* root,int value,int index = 0,int8_t* map = nullptr ){
  
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
                SearchNode(root->left,value,index+1,map);
            }else{
                map[0] = 0;
                map[1] = '\0';
                return map;
            }
        }
        else{
            if(root->right){
                map[index] = 1;
                SearchNode(root->right,value,index+1,map);
            }else{
                map[0] = 0;
                map[1] = '\0';
                return map;
            }       
        }
    }

    return map;
    
}

void SearchNode_p(struct node* root,int value){
    int index = 0;
    
    int8_t* map = SearchNode(root,value);
    
    if(!map[index]){
        cout << "not found" ; cout.flush();

    }
    
    while(map[index]){
        cout << "ll" ; cout.flush();

        if(map[index] == 1){
            cout << "right" << " | " ; cout.flush();
        }
        else if(map[index]==-1){
            cout << "left" << " | " ; cout.flush();  
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




// node* Successor_bad(struct node* root,int8_t is_first_time = 1 ){
//     if (root){

//         if (is_first_time == 1){
//             if(root->right){
//                 Successor(root->right,0);
//                 is_first_time = 0;
//             }else{
//                 return nullptr;
//             }
//         }
//         if(root->left != nullptr){
//             Successor(root->left,0);
//         }else{
//             return root;
//         } 
//     }          
    
// }

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






int main(){
    node *tree = (node*)malloc(sizeof(node));

    InsertNode(tree,5);
    InsertNode(tree,1);
    InsertNode(tree,7);
    InsertNode(tree,6);
    InsertNode(tree,2);
    InsertNode(tree,0);

    
    node* ptr = PredecessorRec(tree);
    if (ptr){
        cout << ptr->data << endl;
    }else{
        cout << "nullptr" << endl;
    }
    

    return 1;
}

