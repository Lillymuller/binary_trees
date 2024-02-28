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
	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}

	if (value == (*tree)->n)
	{
		return (NULL); /*Node with the value already exists*/
	}
	else if (value < (*tree)->n)
	{
		if ((*tree)->left != NULL)
		{
			return (bst_insert(&((*tree)->left), value)); /*Recur on the left subtree*/
		}
		else
		{
			(*tree)->left = binary_tree_node(*tree, value);
			return ((*tree)->left);
		}
	}
	else
	{
		if ((*tree)->right != NULL)
		{
			return (bst_insert(&((*tree)->right), value));
			/*Recur on the right subtree*/
		}
		else
		{
			(*tree)->right = binary_tree_node(*tree, value);
			return ((*tree)->right);
		}
	}
}
