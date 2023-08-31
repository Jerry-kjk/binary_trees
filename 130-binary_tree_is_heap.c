#include "binary_trees.h"

/**
 * size - gets the size of a binary tree
 * @tree: pointer to the root node of the tree
 * Return: the size of the tree. 0 if it is NULL.
 */

int size(const binary_tree_t *tree)
{
	int left = 0, right = 0;

	if (tree == NULL)
		return (0);

	left = size(tree->left);
	right = size(tree->right);

	return (1 + left + right);
}

/**
 * is_heap - checks if a binary tree is a max heap
 * @tree: pointer to the root node of the subtree
 * @ind: the index of the current node
 * @num_nodes: the number of nodes in the tree
 * @max: the maximum value a node can be
 *
 * Return: 1 if tree is max heap.
 */

int is_heap(const binary_tree_t *tree, int ind, int num_nodes, int max)
{
	int left = 0, right = 0;

	if (tree == NULL)
		return (1);

	if (ind >= num_nodes)
		return (0);

	if (tree->n > max)
		return (0);

	left = is_heap(tree->left, (2 * ind + 1), num_nodes, tree->n);
	right = is_heap(tree->right, (2 * ind + 2), num_nodes, tree->n);

	return ((left == 1 && right == 1) ? 1 : 0);
}

/**
 * binary_tree_is_heap - checks if a binary tree is a valid Max Binary Heap
 * @tree: pointer to the root node of the tree
 * Return: 1 if tree is max heap. 0 if not or if tree is NULL.
 */

int binary_tree_is_heap(const binary_tree_t *tree)
{
	int num_nodes;

	if (tree == NULL)
		return (0);

	num_nodes = size(tree);

	return (is_heap(tree, 0, num_nodes, INT_MAX));
}
