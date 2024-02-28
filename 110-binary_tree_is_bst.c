#include "binary_trees.h"

/**
*is_bst_search - it serchs the value of the nodes, puts in order
*@tree: A pointer to the root node of the tree
*@lower: the smallest value of a node
*@higher: the largest value of a node
*Return: if tree is BST 1, otherwise 0
*
*/

int is_bst_search(const binary_tree_t *tree, int lower, int higher)
{

        if (!tree)
                return (1);

        if (tree->n <= lower || tree->n >= higher)
                return (0);

        return (is_bst_search(tree->left, lower, tree->n) && is_bst_search(tree->right, tree->n, higher));

}




/**
*binary_tree_is_bst -  checks if a binary tree is a valid Binary Search Tree
*@tree: a pointer to the root node of the tree to check
*Return: 1 if tree is valid BST and 0 otherwise
*Description: left subtrees contains nodes values less than the node’s value
*right subtrees contain nodes value greater thatn the node's value
*left and right subtree each must also be a binary search trees
*There must be no duplicate values
*
*/

int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (is_bst_search(tree, INT_MIN, INT_MAX));

}
