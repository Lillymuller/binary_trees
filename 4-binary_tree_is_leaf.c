#include "binary_trees.h"

/**
*
*binary_tree_is_leaf - End nodes with out child node
*@node: a pointer to the node to check
*Return: 1 if nnode is a leaf, 0 otherwise
*Description: If node is NULL, return 0
*
*/

int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (node == NULL)
		return (0);

	if (node->left)
		return (0);
	if (node->right)
		return (0);

	return (1);
}
