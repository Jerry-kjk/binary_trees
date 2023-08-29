#include "binary_trees.h"

/**
 * binary_tree_height - measures the height of a binary tree.
 * @tree: pointer to the root node of the tree to measure the height.
 * Return: 0 if tree is NULL.
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t lef = 0;
	size_t rig = 0;

	if (!tree)
		return (0);

	if (tree->left)
		lef = 1 + binary_tree_height(tree->left);
	if (tree->right)
		rig = 1 + binary_tree_height(tree->right);

	if (lef > rig)
		return (lef);
	return (rig);
}
