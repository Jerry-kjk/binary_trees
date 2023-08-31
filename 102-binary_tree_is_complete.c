#include "binary_trees.h"

/**
 * count_nodes - counts the number of nodes in the binary tree.
 * @root: pointer to tree's nodes.
 * Return: number of nodes.
 */

int count_nodes(binary_tree_t *root)
{
	if (!root)
		return (0);

	return (1 + count_nodes(root->left) + count_nodes(root->right));
}

/**
 * is_complete - checks whether the binary tree is complete.
 * @root: pointer to tree's nodes.
 * @index: Index of the node been evaluated.
 * @n: number of trees node.
 * Return: 1 if the tree is a heap, 0 otherwise.
 */

int is_complete(binary_tree_t *root, int index, int n)
{
	if (!root)
		return (0);

	if (index >= n)
		return (0);
	if (!root->left && !root->right)
		return (1);
	if (root->right && !root->left)
		return (0);
	if (root->left && !root->right)
		return (is_complete(root->left, index * 2 + 1, n));

	return (is_complete(root->left, index * 2 + 1, n) &&
		is_complete(root->right, index * 2 + 2, n));
}

/**
 * binary_tree_is_complete - checks if a binary tree is complete.
 * @tree: pointer to the root node of the tree to check.
 * Return: 0 if tree is NULL.
 */

int binary_tree_is_complete(const binary_tree_t *tree)
{
	int node;
	binary_tree_t *root;

	if (!tree)
		return (0);

	root = (binary_tree_t *)tree;
	node = count_nodes(root);

	return (is_complete(root, 0, node));
}
