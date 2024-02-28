#include "binary_trees.h"

/**
 * binary_tree_rotate_left - performs a left-rotation on a binary tree
 * @tree: a pointer to the root node of the tree to rotate
 * Return: a pointer to the new root node of the tree once rotated
 */

binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	if (!tree || !tree->right)
	{
		return (NULL);
	}

	tree->right->left = tree;
	tree->right = tree->right->left;

	if (tree->right->left)
	{
		tree->right->left->parent = tree;
	}

	tree->right->left = tree->parent;
	tree->parent = tree->right;
	tree->right->parent = tree->right->left;

	if (tree->right->left)
	{
		if (tree->right->left->left == tree)
		{
			tree->right->left->left = tree->right;
		}
		else
		{
			tree->right->left->right = tree->right;
		}
	}

	return (tree->right);
}
