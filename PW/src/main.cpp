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

   
    cout << __Successor(SearchNode(tree,5))[0]  << " | " << __Successor(SearchNode(tree,5))[1] << endl;

    return 1;
}

