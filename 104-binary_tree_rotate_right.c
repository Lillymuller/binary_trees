#include "binary_trees.h"

/**
 * binary_tree_rotate_right - performs a right-rotation on a binary tree
 * @tree: a pointer to the root node of the tree to rotate
 * Return: a pointer to the new root node of the tree once rotated
 */

binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *top, *new, *parent;

	if (!tree || !tree->left)
	{
		return (NULL);
	}

	top = tree->left;
	if (!top)
	{
		return (NULL);
	}

	new = top->right;
	top->right = tree;
	tree->left = new;

	if (new)
	{
		new->parent = tree;
	}

	parent = tree->parent;
	tree->parent = top;
	top->parent = new;

	while (parent)
	{
		if (parent->left == tree)
			parent->left = top;
		else
			parent->right = top;
		break;
	}

	return (top);
}
