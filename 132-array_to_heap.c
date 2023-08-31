#include "binary_trees.h"

/**
 * array_to_heap - builds a max binary heap tree from an array.
 * @array: pointer to the first element of the array to be converted.
 * @size: number of element in the array.
 * Return: a pointer to the root node of the heap or NULL on failure.
 */

heap_t *array_to_heap(int *array, size_t size)
{
	size_t i;
	heap_t *root = NULL;

	if (!array)
		return (NULL);

	root = heap_insert(&root, array[0]);
	for (i = 1; i < size; i++)
		heap_insert(&root, array[i]);

	return (root);
}
