#include "binary_trees.h"

/**
*binary_tree_uncle - finds the uncle of a node
*@node: a pointer to the node to find the uncle
*Return: if node is NULL return NULL
*if no uncle return NULL
*
*/

binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (!node)
		return (NULL);

	if (!node->parent || !node->parent->parent)
		return (NULL);

	if (node->parent->parent->left == node->parent)
		return (node->parent->parent->right);
	return (node->parent->parent->left);
}
