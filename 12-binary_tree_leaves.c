#include "binary_trees.h"

/**
 * binary_tree_leaves - counts the leaves in a binary tree.
 * @tree: pointer to the root node of the tree to count the number of leaves.
 * Return: 0 if tree is NULL.
 */

size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t nodes = 0;

	if (!tree)
		return (0);

	if (!(tree->left) && !(tree->right))
		return (1);

	nodes += binary_tree_leaves(tree->left);
	nodes += binary_tree_leaves(tree->right);

	return (nodes);
}
