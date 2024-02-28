#include "binary_trees.h"


/**
 * array_to_bst - builds a Binary Search Tree from an array
 * @array: pointer to the first element of the array to be converted
 * @size: the number of element in the array
 * Return: pointer to the root node of the created BST, or NULL on failure
 * Description: If a value is already present in the tree, must be ignored
 *
 */

bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *tree = NULL;
	size_t a = 0, b;

	if (!array)
		return (NULL);

	while (a < size)
	{
		/* check for duplication before insertion */
		for (b = 0; b < a; b++)
		{
			if (array[b] == array[a])
				break; /* duplication found skip insertion */
		}

		if (b == a)
		{
			/* No duplication found insert into BST */
			if (bst_insert(&tree, array[a]) == NULL)
				return (NULL); /* allocation failure */
		}
		a++;
	}

	return (tree);
}
