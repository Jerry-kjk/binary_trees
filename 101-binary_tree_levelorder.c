#include "binary_trees.h"

/**
 * binary_tree_height_aux -  gets the height of the tree.
 * @tree: pointer to the root node of the tree.
 * Return: the height of the tree.
 */

size_t	binary_tree_height_aux(const binary_tree_t *tree)
{
	size_t h_left = 0, h_right = 0;

	if (!tree)
		return (0);

	if (tree->left)
		h_left = 1 + binary_tree_height_aux(tree->left);
	if (tree->right)
		h_right = 1 + binary_tree_height_aux(tree->right);

	if (h_left > h_right)
		return (h_left);
	return (h_right);
}

/**
 * print_level_order - prints each binary tree node at a certain level.
 * @tree: pointer to the root node of the tree.
 * @level: level of the tree to be processed.
 * @func: the function to call for the value of each node.
 */

void print_level_order(const binary_tree_t *tree, int level, void (*func)(int))
{
	if (!tree)
		return;

	if (level == 1)
		func(tree->n);
	else if (level > 1)
	{
		print_level_order(tree->left, level - 1, func);
		print_level_order(tree->right, level - 1, func);
	}
}

/**
 * binary_tree_levelorder - level-order traverses a binary tree
 * @tree: pointer to the root node of the tree.
 * @func: the function to call for the value of each node.
 */

void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	int hgt = 0;
	int len = 1;

	if (!tree || !func)
		return;

	hgt = binary_tree_height_aux(tree) + 1;

	while (len <= hgt)
	{
		print_level_order(tree, len, func);
		len++;
	}
}
