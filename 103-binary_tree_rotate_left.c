#include "binary_trees.h"

/**
 * binary_tree_rotate_left -  performs a left-rotation on a binary tree.
 * @tree: pointer to the root node of the tree to rotate.
 * Return: A pointer to the new root node of the rotated tree.
 */

binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *pivot, *parent = tree;

	if (!tree)
		return (NULL);

	pivot = parent->right;
	if (!pivot)
		return (tree);

	if (pivot->left)
		pivot->left->parent = parent;

	parent->right = pivot->left;
	pivot->left = parent;
	pivot->parent = parent->parent;
	parent->parent = pivot;

	if (pivot->parent && pivot->parent->left == parent)
		pivot->parent->left = pivot;
	else if (pivot->parent)
		pivot->parent->right = pivot;

	return (pivot);
}
