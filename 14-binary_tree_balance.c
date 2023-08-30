#include "binary_trees.h"

/**
 * binary_tree_height_balance - measures the balance factor of a binary tree.
 * @tree: pointer to the root node of the tree to measure the balance factor.
 * Return: height or 0 if tree is NULL.
 */

int binary_tree_balance(const binary_tree_t *tree)
{
	size_t left_height = 0, right_height = 0;

	if (!tree)
		return (0);

	if (tree->left)
		left_height = 1 + binary_tree_height_balance(tree->left);
	if (tree->right)
		right_height = 1 + binary_tree_height_balance(tree->right);

	if (left_height > right_height)
		return (left_height);
	return (right_height);
}

/**
 * binary_tree_balance - measures the balance factor of a binary tree.
 * @tree: pointer to the root node of the tree to measure the balance factor.
 * Return: 0 if tree is NULL.
 */

int binary_tree_balance(const binary_tree_t *tree)
{
	size_t left_height = 0, right_height = 0;

	if (!tree)
		return (0);

	if (tree->left)
		left_height = 1 + binary_tree_height_balance(tree->left);
	if (tree->right)
		right_height = 1 + binary_tree_height_balance(tree->right);
	return (left_height - right_height);
}
