#include <iostream>
#include <BST.h>


using namespace std;


int main(){
    node *tree = (node*)malloc(sizeof(node));
    int chioce;
    
    while (1){
        menu();
        scanf("%d",&chioce);
        system("clear");

        switch (chioce){
            case 1:
                cout << "Enter the value to insert: ";
                cin >> chioce;
                InsertNode(tree,chioce);
                break;
            case 2:
                cout << "Enter the value to search: ";
                cin >> chioce;
                if (DFSearch(tree,chioce)){
                    cout << "The value is found" << endl;
                }else{
                    cout << "The value is not found" << endl;
                }

                break;
            case 3:
                cout << "Enter the value to delete: ";
                cin >> chioce;
                DeleteNode(tree,chioce);
                break;
            case 4:
                InOrderTraversal(tree);
                break;
            case 5:
                PreOrderTraversal(tree);
                break;
            case 6:
                PostOrderTraversal(tree);
                break;
            case 7:
                cout << "The depth of the tree is: " << MaxDepth(tree) << endl;
                break;
           
            case 0:
                return 0;
            default:
                cout << "Invalid choice" << endl;
        }
    

    }
}
