#include "binary_trees.h"

/**
* binary_tree_is_full - checks if a binary tree is full
* @tree: pointer to the root node of the tree to check
* Return: 0 if tree is not full, 1 otherwise
* Description: If tree is NULL, your function must return 0
*/

int binary_tree_is_full(const binary_tree_t *tree)
{
	if (tree == NULL)
	{
		/* Empty tree is not considered full */
		return (0);
	}

	/* Check for violation: one child but not both */
	if ((tree->left == NULL) != (tree->right == NULL))
	{
		return (0);
	}

	/* Recursively check children if both present */
	if (tree->left != NULL)
	{
		return (binary_tree_is_full(tree->left) && binary_tree_is_full(tree->right));
	}

	/* If we reach here, both children are NULL, so implicitly full */
	return (1);
}
