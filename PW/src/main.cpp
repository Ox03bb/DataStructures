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

    DeleteNode(tree,5);
    DeleteNode(tree,2);
    // cout << "main" << tree << endl;

    // cout << tree << " ";
    // cout << tree->data << " ";
    // cout << tree->left->data << " ";
    // cout << tree->right->data << " ";
    // cout << tree->left->left->data << " ";
    // cout << tree->left->right->data << " ";
    // cout << tree->right->left->data << " ";
    // cout << endl;

    InOrderTraversal(tree);

    return 1;
}

//       5
//      / \
//     1   7
//    / \  /
//   0   2 6