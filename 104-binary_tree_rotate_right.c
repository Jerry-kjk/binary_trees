#include "binary_trees.h"

/**
 * binary_tree_rotate_right -  performs a right-rotation on a binary tree.
 * @tree: pointer to the root node of the tree to rotate.
 * Return: pointer to the new root node of the rotated tree.
 */

binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *pivot, *parent = tree;

	if (!tree)
		return (NULL);

	pivot = parent->left;
	if (!pivot)
		return (tree);

	if (pivot->right)
		pivot->right->parent = parent;

	parent->left = pivot->right;
	pivot->right = parent;
	pivot->parent = parent->parent;
	parent->parent = pivot;

	if (pivot->parent && pivot->parent->left == parent)
		pivot->parent->left = pivot;
	else if (pivot->parent)
		pivot->parent->right = pivot;

	return (pivot);
}
