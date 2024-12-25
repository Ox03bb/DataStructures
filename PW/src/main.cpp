#include <iostream>
#include <BST.h>


using namespace std;


int main(){
    node *tree = (node*)malloc(sizeof(node));

    InsertNode(tree,5);
    InsertNode(tree,1);
    InsertNode(tree,7);
    InsertNode(tree,6);
    InsertNode(tree,2);
    InsertNode(tree,0);

    // DeleteNode(tree,0);
    // DeleteNode(tree,2);
    
    // InOrderTraversal(tree);
    Visualization(tree) ;

    return 1;
}

//       5
//      / \
//     1   7
//    / \  /
//   0   2 6


//       5
//      / \
//     1   7
//    / \  / \
//   0   2 6  8
//  / \ / \ \
// 3  4 9 10 11 

// 1->9