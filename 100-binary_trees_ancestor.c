#include "binary_trees.h"

/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 * @first: is a pointer to the first node
 * @second: is a pointer to the second node
 * Return: a pointer to the lowest common ancestor node of the two given nodes
 * Description: If no common ancestor was found, your function must return NULL
 *
 */

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first, const binary_tree_t *second)
{
	binary_tree_t *parent;

	if (first == NULL || second == NULL)
	{
		return (NULL);
	}

	if (first == second)
	{
		return ((binary_tree_t *)first);
	}

	parent = second->parent;

	/* checks if the first is an ancestor of the second */
	while (parent)
	{
		if (parent == first)
		{
			return ((binary_tree_t *)first); /* ancestor found */
		}
		parent = parent->parent;
	}

	parent = first->parent;
	
	/* checks if the second is an ancestor of the first */
	while (parent)
	{
		 if (parent == second)
                {
                        return ((binary_tree_t *)second); /* ancestor found */
                }
                parent = parent->parent;
	}

	/* No common ancestor found, continue searching */
	return (binary_trees_ancestor(first->parent, second->parent));
}
