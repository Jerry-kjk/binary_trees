#include "binary_trees.h"

/**
 * array_to_avl - Builds an AVL tree from an array.
 * @array: A pointer to the first element of the array to be converted.
 * @size: The number of element in the array.
 * Return: A pointer to the root node of the created AVL tree, NULL on failure.
 */

avl_t *array_to_avl(int *array, size_t size)
{
	size_t i;
	avl_t *tree = NULL;

	if (!array || size == 0)
		return (NULL);

	tree = avl_insert(&tree, array[0]);
	for (i = 1; i < size; i++)
		avl_insert(&tree, array[i]);

	return (tree);
}
