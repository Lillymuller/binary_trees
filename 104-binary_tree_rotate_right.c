#include "binary_trees.h"

/**
 * binary_tree_rotate_right - performs a right-rotation on a binary tree
 * @tree: a pointer to the root node of the tree to rotate
 * Return: a pointer to the new root node of the tree once rotated
 */

binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	if (!tree || !tree->left)
	{
		return (NULL);
	}

	tree->left->right = tree;
	tree->left = tree->left->right;

	if (tree->left->right)
	{
		tree->left->right->parent = tree;
	}

	tree->left->right = tree->parent;
	tree->parent = tree->left;
	tree->left->parent = tree->left->right;

	if (tree->left->right)
	{
		if (tree->left->right->left == tree)
		{
			tree->left->right->left = tree->left;
		}
		else
		{
			tree->left->right->right = tree->left;
		}
	}

	return (tree->left);
}
