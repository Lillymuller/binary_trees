#include "binary_trees.h"

/**
 * binary_tree_rotate_left - performs a left-rotation on a binary tree
 * @tree: a pointer to the root node of the tree to rotate
 * Return: a pointer to the new root node of the tree once rotated
 */

binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *top, *new, *parent;

	if (!tree || !tree->right)
	{
		return (NULL);
	}

	top = tree->right;
	if (!top)
		return (NULL);

	new = top->left;
	top->left = tree;
	tree->right = new;

	if (new)
	{
		new->parent = tree;
	}

	parent = tree->parent;
	tree->parent = top;
	top->parent = parent;

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
