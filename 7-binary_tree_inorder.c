#include "binary_trees.h"

/**
*binary_tree_inorder - Goes through binary tree using left, root, right order
*@tree: a pointer to the root node of the tree to traverse
*@func: a pointer to a function to call for each node
*Description: If tree or func is NULL, do nothing
*/

void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;

	if (tree != NULL && func != NULL)
	{
		binary_tree_inorder(tree->left, func);
		func(tree->n);
		binary_tree_inorder(tree->right, func);
	}
}
