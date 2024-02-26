#include "binary_trees.h"

/**
*
*check_tree_is_full - checks if a binary tree is full
*@tree: pointer to the root node of the tree to check
*Return: 0 if tree is not full, 1 otherwise
*Description: If tree is NULL, your function must return 0
*
*/

int check_tree_is_full(const binary_tree_t *tree)
{
	if (tree != NULL)
	{
		if ((tree->left && !tree->right) || (!tree->left && tree->right))
			return (0);
		if (check_tree_is_full(tree->left) || 
				check_tree_is_full(tree->right))
			return (0);
	}

	return (1);
}



/**
*
*
*/

int binary_tree_is_full(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (check_tree_is_full(tree));

}
