#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree.
 * @tree: pointer to the root node of the tree to measure the height.
 * Return: the height of the tree. If tree is NULL, return 0.
 */

size_t depth(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	else
		return (depth(tree->left) + 1 + depth(tree->right));
}

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect.
 * @tree: pointer to the root node of the tree to check.
 * Return: 0 if tree is NULL.
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t left_height = 0, right_height = 0;

	if (!tree)
		return (0);

	if (tree && (!tree->left && !tree->right))
		return (1);

	left_height = depth(tree->left);
	right_height = depth(tree->right);

	if ((left_height - right_height) == 0)
		return (1);

	return (0);
}
