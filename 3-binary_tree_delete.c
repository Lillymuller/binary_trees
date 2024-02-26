#include "binary_trees.h"

/**
*
*binary_tree_delete - Deletes the required node
*@tree: a pointer to the root node of the tree to delete
*Return: void
*Description: If tree is NULL, do nothing
*
*/

void binary_tree_delete(binary_tree_t *tree)
{
	if (tree == NULL)
		return;

	if (tree)
	{
		binary_tree_delete(tree->left);
		binary_tree_delete(tree->right);

		free(tree);
	}
}
