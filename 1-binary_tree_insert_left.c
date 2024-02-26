#include "binary_trees.h"

/**
*
*binary_tree_insert_left - Creates a chiled node on the left side
*@parent: pointer to the node to insert the left-child
*@value: the value to store in the new node
*Return: Null of failure or if parent is NULL 
*return a pointer to the created node
*Description: If parent already has a left-child, the new node must take its
*place, and the old left-child must be set as the left-child of the new node
*
*/

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *left_child;

	left_child = binary_tree_node(parent, value);

	if (parent->left != NULL)
	{
		left_child->left = parent->left;
		parent->left->parent = left_child;
	}
	parent->left = left_child;

	return (left_child);

	if (left_child == NULL)
		return (NULL);

	if (parent == NULL)
		return (NULL);
}
