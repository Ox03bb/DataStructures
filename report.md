# Report on Binary Search Tree (BST) Implementation

## 01. Overview

This project implements a Binary Search Tree (BST) in C. The BST is a data structure that organizes data hierarchically, allowing efficient insertion, deletion, and search operations with an average time complexity of O(log n) for balanced trees. The project also includes an in-order traversal function for displaying the tree elements in sorted order.

> we try to make a scalable profissional lib of the BST data structure, even though we have not enough time to implement all the functionalities, we will continue to improve the lib and add more functionalities in the future.


## 02. Functionalities
### 02.0. Node Structure:

- The `node` structure contains:  
  - `data`: The value stored in the node.  
  - `left`: Pointer to the left child node.  
  - `right`: Pointer to the right child node.

The program provides the following functionalities:

### 02.1 CRUD Operations
the file `src/lib/crud.c` contains the following functions:

- **Insertion**
  - `InsertNode`: This function is responsible for inserting a new node with the specified value into the data structure.

- **Search**
  - `DFSearch`: This function performs a Depth First Search to find a node with the specified value in the data structure.
  - `BFSearch`: This function performs a Breadth First Search to find a node with the specified value in the data structure.
  - `SearchMapNode`: This function searches for a node with the specified value and returns a map of the search path.
  - `SearchMapNode_p`: This function searches for a node with the specified value and prints the search path.

- **Deletion**
  - `DeleteNode`: This function deletes a node with the specified value from the data structure.

### 02.2 Other Functionalities
the file `src/lib/func.c` contains the following functions:
- **Traversal methods**
  - `InOrderTraversal`: This function performs an in-order traversal of the BST.
  - `PreOrderTraversal`: This function performs a pre-order traversal of the BST.
  - `PostOrderTraversal`: This function performs a post-order traversal of the BST.

- **Successor and Predecessor**
  - `Successor`: This function finds the successor of a given node.
  - `SuccessorRec`: This function recursively finds the successor of a given node.
  - `Predecessor`: This function finds the predecessor of a given node.
  - `PredecessorRec`: This function recursively finds the predecessor of a given node.

- **Other Operations**
  - `ToArray`: This function converts the BST to an array.
  - `MaxDepth`: This function finds the maximum depth of the BST.
  - `menu`: This function displays the menu for BST operations.


## 03. Group Members

- Ali.D.E Bouakaz
- Zouaoui Djasser
- Boubrgoug Abdelouadoud
- Moudjari Abdelrahmane

