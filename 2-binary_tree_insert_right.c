#include "binary_trees.h"

/**
*
*binary_tree_insert_right - Creates a chiled node on the right side
*@parent: pointer to the node to insert the right-child
*@value: the value to store in the new node
*Return: Null of failure or if parent is NULL 
*return a pointer to the created node
*Description: If parent already has a right-child, the new node must take its
*place, and the old right-child must be set as the right-child of the new node
*
*/

binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *right_child;

	right_child = binary_tree_node(parent, value);

	if (parent->right != NULL)
	{
		right_child->right = parent->right;
		parent->right->parent = right_child;
	}
	parent->right = right_child;

	return (right_child);

	if (right_child == NULL)
		return (NULL);

	if (parent == NULL)
		return (NULL);
}
