#include "binary_trees.h"

/**
*
*binary_tree_balance -  measures the balance factor of a binary tree
*@tree: a pointer to the root node of the tree to measure the balance factor
*Return: 0 on success
*Decription: if tree is NULL return 0
*
*/

int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	if (tree != NULL)
	{
		return (binary_tree_height(tree->left) -
				binary_tree_height(tree->right));
	}

	return (0);
}






/**
*binary_tree_height -  measures the height of a binary tree
*@tree: a pointer to the root node of the tree to measure the height
*Return: height of tree
*Description: If tree is NULL, your function must return 0
*
*/

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height = 0;
	size_t right_height = 0;

	if (tree == NULL)
		return (0);

	if (tree->left)
	{
		left_height = 1 + binary_tree_height(tree->left);
	}
	else
	{
		left_height = 1;
	}

	if (tree->right)
	{
		right_height = 1 + binary_tree_height(tree->right);
	}
	else
	{
		right_height = 1;
	}

	if (left_height > right_height)
	{
		return (left_height);
	}
	else
	{
		return (right_height);
	}
}
