#include "binary_trees.h"

/**
*binary_tree_nodes - counts the nodes with at least 1 child in a binary tree
*@tree: a pointer to the root node of the tree to count the number of nodes
*Return: number of nodes with 1 child
*Description: If tree is NULL, the function must return 0
*A NULL pointer is not a node
*
*/

size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t count_node = 0;

	if (tree == NULL)
		return (0);

	if (tree != NULL)
	{
		if (tree->left != NULL || tree->right != NULL)
		{
			count_node = count_node + 1;
		}

		count_node = count_node + binary_tree_nodes(tree->left);
		count_node = count_node + binary_tree_nodes(tree->right);
	}

	return (count_node);

}
