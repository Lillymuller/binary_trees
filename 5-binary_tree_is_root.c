#include "binary_trees.h"

/**
*
*binary_tree_is_root - checks given node is a root
*@node: a pointer to the node to check
*Return: 1 if node is root, 0 otherwise
*Description: If node is NULL, return 0
*
*/

int binary_tree_is_root(const binary_tree_t *node)
{
	if (node == NULL)
		return (0);

	if (node->parent)
		return (0);

	return (1);
}
