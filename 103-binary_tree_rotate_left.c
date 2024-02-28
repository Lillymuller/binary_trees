#include "binary_trees.h"

/**
 * binary_tree_rotate_left - performs a left-rotation on a binary tree
 * @tree: a pointer to the root node of the tree to rotate
 * Return: a pointer to the new root node of the tree once rotated
 */

binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *top, *new;

	/* can't rorate with out a valid right child */
	if (!tree || !tree->right)
	{
		return (NULL);
	}

	/*perform rotation directly on pointer */
	tree->right->left = tree; /*attach  new left child*/
	tree->parent = tree->right; /* update parent pivot */

	/*handles top and parent */
	top = tree->right; /*stores top return */
	new = top->left;
	tree->right = new; /* attaches left pivot to right */

	if (new)
	{
		new->parent = tree;
	}

	top->parent = tree->parent;

	/* updates the grandparents child */
	if (top->parent)
	{
		if (top->parent->left == tree)
		{
			top->parent->left = top;
		}
		else
		{
			top->parent->right = top;
		}
	}

	return (top);
}
