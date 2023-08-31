#include "binary_trees.h"

/**
 * sorted_array_to_avl_revursive - recursive array to avl.
 * @array: pointer to array.
 * @start: the start index of the array.
 * @end: the end index of the array.
 * Return: a pointer to the root node of the new AVL tree or NULL on failure.
 */

avl_t *sorted_array_to_avl_revursive(int *array, int start, int end)
{
	avl_t *root;
	int h;

	if (end < start)
		return (NULL);

	h = (end + start) / 2;

	root = binary_tree_node(NULL, array[h]);
	if (!root)
		return (NULL);

	root->left = sorted_array_to_avl_revursive(array, start, h - 1);
	root->right = sorted_array_to_avl_revursive(array, h + 1, end);
	if (root->left)
		root->left->parent = root;
	if (root->right)
		root->right->parent = root;
	return (root);
}

/**
 * sorted_array_to_avl - builds an AVL tree from a sorted array.
 * @array: pointer to the first element of the array to be converted.
 * @size: number of element in the array.
 * Return: a pointer to the root node of the new AVL tree or NULL on failure.
 */

avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (!array || size < 1)
		return (NULL);
	return (sorted_array_to_avl_revursive(array, 0, size - 1));
}
