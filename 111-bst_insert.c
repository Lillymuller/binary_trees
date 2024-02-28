#include "binary_trees.h"

/**
 * bst_insert - inserts a value in a Binary Search Tree
 * @tree: double pointer to the root node of the BST to insert the value
 * @value: value to store in the node to be inserted
 * Return: pointer to the created node, or NULL on failure
 * Description: If the address stored in tree is NULL, the created node must
 * become the root node. If the value is already present in the tree
 * it must be ignored.
 *
 */

bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *node = *tree;
	bst_t *tmp;

	if (!tree)
	{
		return (NULL);
	}

	/* Find the insertion position using recursion */
	while (node)
	{
		if (value < node->n)
		{
			/* move left if smaller */
			if (!node->left)
			{
				break; /* insertion point found */
			}
			else
			{
				node = node->left;
			}
		}
		else if (value > node->n)
		{
			/* move right if large */
			if (!node->right)
			{
				break; /* insertion point found */
			}
			else
			{
				node = node->right;
			}
		}
		return (NULL);
	}
	tmp = binary_tree_node(node, value);
	if (!tmp)
		return (NULL);
	if (!node)
	{
		/* empty tree, tmp becomes the root */
		return (*tree = tmp);
	}
	else if (value < node->n)
	{
		return (node->left = tmp);
	}
	else
	{
		return (node->right = tmp);
	}

	return (tmp);
}
