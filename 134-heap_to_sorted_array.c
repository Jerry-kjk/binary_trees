#include "binary_trees.h"

/**
 * heap_size - gets the size of a heap
 * @root: pointer to the root node of the heap
 *
 * Return: the size of the heap. 0 if it is NULL
 */

size_t heap_size(heap_t *root)
{
	size_t left = 0, right = 0;

	if (root == NULL)
		return (0);

	left = heap_size(root->left);
	right = heap_size(root->right);

	return (1 + left + right);
}

/**
 * heap_to_sorted_array - converts a binary heap into a sorted integer array
 * @heap: pointer to the root node of the heap
 * @size: pointer to the size of the array
 *
 * Return: an array of integers
 */

int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	int *res;
	size_t s, i;
	int max;

	if (heap == NULL || size == NULL)
		return (NULL);

	s = heap_size(heap);
	*size = s;

	res = malloc(sizeof(int) * s);
	if (res == NULL)
		return (NULL);

	for (i = 0; i < s; i++)
	{
		max = heap_extract(&heap);
		if (max == 0)
		{
			free(res);
			return (NULL);
		}

		res[i] = max;
	}

	return (res);
}
