#include "binary_trees.h"

/**
 * is_bst_helper - Checks if a binary tree is a valid BST.
 * @tree: pointer to the root node of the tree to check.
 * @min: minimum value a node in the tree can have.
 * @max: maximum value a node in the tree can have.
 * Return: 1 if the tree is a valid BST, otherwise 0.
 */

int is_bst_helper(const binary_tree_t *tree, int min, int max)
{
	if (tree == NULL)
		return (1);

	if (tree->n <= min || tree->n >= max)
		return (0);

	return (is_bst_helper(tree->left, min, tree->n) &&
			is_bst_helper(tree->right, tree->n, max));
}

/**
 * binary_tree_is_bst - Checks if a binary tree is a valid BST.
 * @tree: pointer to the root node of the tree to check.
 * Return: 1 if the tree is a valid BST, otherwise 0.
 */

int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (is_bst_helper(tree, INT_MIN, INT_MAX));
}
