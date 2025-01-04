# Binary Search Tree (BST) 

## Installation
 
### 1. Clone the repository.
```bash
	git clone https://github.com/Ox03bb/DataStructures.git
```
### 2. Change the directory.
```bash
	cd DataStructures/BinarySearchTree
```
### 3. build the project.
```bash
	cd build
	cmake ..
	cmake --build .
```
### 4. Run the executable.
```bash
	./DataStructures
```



## Function List

- `InsertNode(node *root, int value)`: Inserts a node with the given value into the BST.
- `DFSearch(struct node* root, int value)`: Performs Depth First Search to find a node with the given value.
- `BFSearch(node* root, int value)`: Performs Breadth First Search to find a node with the given value.
- `SearchMapNode(struct node* root, int value, int index = 0, int8_t* map = nullptr)`: Searches for a node and maps its path.
- `SearchMapNode_p(struct node* root, int value)`: Searches for a node and prints its path.
- `DeleteNode(struct node* root, int value)`: Deletes a node with the given value from the BST.
- `Successor(struct node* root)`: Finds the successor of a given node.
- `SuccessorRec(struct node* root, int8_t ft = 1)`: Recursively finds the successor of a given node.
- `Predecessor(struct node* root)`: Finds the predecessor of a given node.
- `PredecessorRec(struct node* root, int8_t ft = 1)`: Recursively finds the predecessor of a given node.
- `InOrderTraversal(struct node* root)`: Performs in-order traversal of the BST.
- `PreOrderTraversal(struct node* root)`: Performs pre-order traversal of the BST.
- `PostOrderTraversal(struct node* root)`: Performs post-order traversal of the BST.
- `ToArray(node* root)`: Converts the BST to an array.
- `MaxDepth(node* root)`: Finds the maximum depth of the BST.
- `menu()`: Displays the menu for BST operations.
