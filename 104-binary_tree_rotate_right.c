#include "binary_trees.h"

/**
 * binary_tree_rotate_right - performs a right-rotation on a binary tree
 * @tree: a pointer to the root node of the tree to rotate
 * Return: a pointer to the new root node of the tree once rotated
 */

binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *top, *new;
	if (!tree || !tree->left)
	{
		return (NULL);
	}
	top = tree->left;
	new = top->right;
	top->right = tree;
	tree->left = new;

	if (new)
	{
		new->parent = tree;
	}

	new = tree->parent;
	tree->parent = top;
	top->parent = new;

	if (new)
	{
		new->left == tree ? new->left = top : new->right = top;
	}

	return (top);
}
