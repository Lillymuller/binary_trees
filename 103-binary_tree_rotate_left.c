#include "binary_trees.h"

/**
 * binary_tree_rotate_left - performs a left-rotation on a binary tree
 * @tree: a pointer to the root node of the tree to rotate
 * Return: a pointer to the new root node of the tree once rotated
 */

binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *top, *parent;

	/* can't rorate with out a valid right child */
	if (!tree || !tree->right)
	{
		return (NULL);
	}

	/*handles top and parent */
	top = tree->right; /*stores top return */
	parent = tree->parent;

	while (1)
	{
		tree->right = top->left;
		top->left = tree;
		tree->parent = top;
		
		if (top->left)
		{
			top->left->parent = tree;
		}
		
		if (parent)
		{
			if (parent->left == tree)
			{
				parent->left = top;
			}
			else
			{
				parent->right = top;
			}
		}
		top->parent = parent;
		break;
	}

	return (top);
}
