#include "binary_trees.h"

/**
 * min_finder - Finds the minimum root.
 * @root: pointer to the root node of the tree where you will remove a node.
 * Return: the minimum number.
 */

bst_t *min_finder(bst_t *root)
{
	while (root->left != NULL)
		root = root->left;
	return (root);
}

/**
 * bst_remove - Removes a node from a Binary Search Tree.
 * @root: Pointer to the root node of the tree where you will remove a node.
 * @value: The value to remove in the tree.
 * Return: A pointer to the new root node of the tree after
 * removing the desired value.
 */

bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *tmp, *parent;

	if (root == NULL)
		return (NULL);
	else if (value < root->n)
		root->left = bst_remove(root->left, value);
	else if (value > root->n)
		root->right = bst_remove(root->right, value);
	else
	{
		if (root->left == NULL && root->right == NULL)
		{
			free(root);
			root = NULL;
		}
		else if (root->left == NULL)
		{
			tmp = root;
			parent = root->parent;
			root = root->right;
			root->parent = parent;
			free(tmp);
		}
		else if (root->right == NULL)
		{
			tmp = root;
			parent = root->parent;
			root = root->left;
			root->parent = parent;
			free(tmp);
		}
		else
		{
			tmp = min_finder(root->right);
			root->n = tmp->n;
			root->right = bst_remove(root->right, tmp->n);
		}
	}
	return (root);
}
