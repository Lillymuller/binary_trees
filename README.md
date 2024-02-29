Binary Trees

Defnitions: 
A binary tree is a tree data structure in which each parent node can have at most two children. Each node of a binary tree consists of three items:

-> data item
-> address of left child
-> address of right child

Types of Binary tree:

1. Full Binary Tree: is a binary tree in which every parent node or internal node has either two or no children.
2. Perfect Binary Tree: is a binary tree i which evry internal node has two child nodes and all the leaf nodes
are at the same level.
3. Complete Binary Tree: is a full binary tree with two difrences
-> every levels must be completely filled
-> All leaf elements must lean towards the left.
-> the last leaf element might not have a right sibiling 

Tree Traversal: Traversing a tree means to visite every node in the tree.

Types of Tree Traversal:

1. Inorder Traversal: left, root, right
2. Preorder Traversal: root, left, right
3. Postorder Traversal: left, right, root

Balanced Binary Tree: 
is a binary tree in which the height of the left and right subtree of anynode differ by not more than one

Binary Search Tree (BST): it is a data structure that allowes us to maintain a sorted list of numbers.
			  it can be used to search the presence of a number in O(log(n))time.

Data structures:
Please use the following data structures and types for binary trees. Don’t forget to include them in your header file.

Basic Binary Tree

/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
struct binary_tree_s
{
    int n;
    struct binary_tree_s *parent;
    struct binary_tree_s *left;
    struct binary_tree_s *right;
};

typedef struct binary_tree_s binary_tree_t;
Binary Search Tree

typedef struct binary_tree_s bst_t;
AVL Tree

typedef struct binary_tree_s avl_t;
Max Binary Heap

typedef struct binary_tree_s heap_t;



AUTHORS:
Yared Kebede
Elelta Alemu
