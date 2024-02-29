#include "binary_trees.h"

/**
*successor_inorder_delete - delets a node with two childs
*@node: the pointer to the node to be removed
*Return: removes the inoder successor from its orgin
*
*/

bst_t *successor_inorder_delete(bst_t *node)
{
	while (node && node->left)
		node = node->left;
	return (node);
}

/**
*successor_delete - delets the successor node
*@root: this is the grand node
*@node: a pointer to the node to be deleted
*Return: points to the new node with successors value
*/

bst_t *successor_delete(bst_t *root, bst_t *node)
{
	bst_t *rt_child = node->right;
	bst_t *lt_child = node->left, *successor;

	if (node->left == NULL)
	{
		if (node == root)
		{
			free(node);
			return (rt_child); }
		if (node == node->parent->left)
			node->parent->left = rt_child;
		else
			node->parent->right = rt_child;
		if (rt_child)
			rt_child->parent = node->parent;
		free(node);
		return (root);
	}
	else if (node->right == NULL)
	{
		if (node == root)
		{
			free(node);
			return (lt_child); }
		if (node == node->parent->left)
			node->parent->left = lt_child;
		else
			node->parent->right = lt_child;
		lt_child->parent = node->parent;
		free(node);
		return (root);
	}
	successor = successor_inorder_delete(node->right);
	node->n = successor->n;
	return (successor_delete(root, successor));
}

/**
*remove_recursive - remove a node with a specific value from the BST
*@root:  the original node
*@node: a pointer to a node
*@value: value of the sucessor
*Return: the new node value after deletion
*/

bst_t *remove_recursive(bst_t *root, bst_t *node, int value)
{
	if (!node)
		return (NULL);
	if (value < node->n)
		return (remove_recursive(root, node->left, value));
	else if (value > node->n)
		return (remove_recursive(root, node->right, value));
	else
		return (successor_delete(root, node));
	return (node);
}

/**
*bst_remove -  removes a node from a Binary Search Tree
*@root: a pointer to the root node of the tree where you will remove a node
*@value: the value to remove in the tree
*Return: a pointer to the new root node of the tree
*after removing the desired value
*/

bst_t *bst_remove(bst_t *root, int value)
{
	return (remove_recursive(root, root, value));
}
