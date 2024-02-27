#include "binary_trees.h"

/**
* check_is_leaf -  checks if a binary tree node is a leaf
* @node:  a pointer to the  node of the tree wich is leaf
* Return: leaf of a node
*
*/

int check_is_leaf(const binary_tree_t *node)
{
	return ((node->left == NULL && node->right == NULL) ? 1 : 0);
}


/**
* find_depth - finds the depth of the binary tree
* @node: ponter to a node
* Return: depth of a Binary tree
*/

size_t find_depth(const binary_tree_t *node)
{
	if (node == NULL)
	{
		return (0); /* Base case: depth of NULL node is 0 */
	}

	if (node->parent)
		return (1 + find_depth(node->parent));
	else
		return (0); /* Depth of current node is 1 + parent's depth */
}


/**
* find_first_leaf - finds the first leaf of a binary tree
* @tree: ponter to a node
* Return: depth of a Binary tree
*/

const binary_tree_t *find_first_leaf(const binary_tree_t *tree)
{
	if (check_is_leaf(tree) == 1)
	{
		return (tree); /* Found a leaf, return it */
	}

	if (tree->left != NULL)
	{
		return (find_first_leaf(tree->left)); /* Check left subtree first */
	}
	else
	{
		return (find_first_leaf(tree->right));
		/* Check right subtree if left is NULL */
	}
}


/**
 * check_perfect_recursive -  checks if a binary tree recursively
 * @node: a pointer to the given node
 * @leaf_depth: checks depth os a leaf
 * @level: checks if the leaf are in the same level
 * Return: if tree is perfect 1 otherwise 0
 *
 */

int check_perfect_recursive(const binary_tree_t *node,
		size_t leaf_depth, size_t level)
{
	if (node == NULL)
	{
		return (0); /* NULL nodes violate the definition of a perfect tree */
	}

	if (check_is_leaf(node))
	{
		if (level == leaf_depth) /* Leaf should be at the correct level */
			return (1);
		else
			return (0);
	}

	return (check_perfect_recursive(node->left, leaf_depth, level + 1) &&
		check_perfect_recursive(node->right, leaf_depth, level + 1));
	/* Both children must be perfect and at the same level */
}

/**
 * binary_tree_is_perfect -  checks if a binary tree is full
 * @tree: a pointer to the root node of the tree to check
 * Return: 0 if tree is NULL
 *
 */

int  binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t leaf_depth = 0;

	if (tree == NULL)
	{
		return (0); /* Empty tree is not perfect */
	}

	/* Find depth of any leaf */
	/* (all leaves have the same depth in a perfect tree) */
	leaf_depth = find_depth(find_first_leaf(tree));

	/* Check if all nodes have both children and */
	/* are at the same level as leaves */
	return (check_perfect_recursive(tree, leaf_depth, 0));
}
