#include "binary_trees.h"

/**
 * avl_insert_full - Inserts a value in an AVL tree.
 * @tree: double pointer to the root node of the AVL tree.
 * @parent: parent of node.
 * @value: the value to insert.
 * Return: a pointer to the new node. NULL on failure.
 */

avl_t *avl_insert_full(avl_t *tree, avl_t *parent, int value)
{
	avl_t *new;

	if (tree == NULL)
	{
		new = binary_tree_node(parent, value);
		if (parent->n > new->n)
			parent->left = new;
		else
			parent->right = new;
		return (new);
	}
	else if (value == tree->n)
		return (NULL);
	else if (value < tree->n)
		return (avl_insert_full(tree->left, tree, value));
	else
		return (avl_insert_full(tree->right, tree, value));
}

/**
 * avl_balance - balances an AVL tree after an insertion.
 * @root: pointer to the root of the tree.
 * @tree: double pointer to the root node of the tree.
 * @value: inserted value.
 */

void avl_balance(avl_t **root, avl_t *tree, int value)
{
	int new_b;

	new_b = binary_tree_balance(tree);
	if (new_b > 1)
	{
		if (tree->left->n > value)
		{
			if (*root == tree)
				*root = tree->left;
			binary_tree_rotate_right(tree);
		}
		else
		{
			if (*root == tree)
				*root = tree->left->right;
			binary_tree_rotate_left(tree->left);
			binary_tree_rotate_right(tree);
		}
	}
	if (new_b < -1)
	{
		if (tree->right->n < value)
		{
			if (*root == tree)
				*root = tree->right;
			binary_tree_rotate_left(tree);
		}
		else
		{
			if (*root == tree)
				*root = tree->right->left;
			binary_tree_rotate_right(tree->right);
			binary_tree_rotate_left(tree);
		}
	}
}

/**
 * avl_insert - inserts a value in an AVL tree.
 * @tree: double pointer to the root node of the AVL tree.
 * @value: the value to insert.
 * Return: a pointer to the new node. NULL on failure.
 */

avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *new, *curr;

	if (tree == NULL)
		return (NULL);
	if (*tree == NULL)
	{
		new = binary_tree_node(NULL, value);
		*tree = new;
		return (new);
	}
	new = avl_insert_full(*tree, NULL, value);

	if (new == NULL)
		return (NULL);

	curr = new->parent;

	while (curr != NULL)
	{
		avl_balance(tree, curr, value);
		curr = curr->parent;
	}
	return (new);
}
