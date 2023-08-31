#include "binary_trees.h"

/**
 * shift_nodes- replaces one node with another in a BST.
 * @tree: double pointer to the root node of the BST.
 * @n1: pointer to the node to replace.
 * @n2: pointer to the replacement node;
 */

void shift_nodes(avl_t **tree, avl_t *n1, avl_t *n2)
{
	if (tree == NULL || n1 == NULL)
		return;

	if (n1->parent == NULL)
		*tree = n2;
	else if (n1 == n1->parent->left)
		n1->parent->left = n2;
	else
		n1->parent->right = n2;

	if (n2 != NULL)
		n2->parent = n1->parent;
}

/**
 * del_rotate_left - left rotates a subtree to balance an AVL tree.
 * @n: pointer to the root node of the subtree.
 * Return: the new root node of the rotated subtree.
 */

avl_t *del_rotate_left(avl_t *n)
{
	avl_t *r_root = NULL;
	avl_t *c_root = NULL;
	int rbf;

	if (n == NULL)
		return (NULL);

	rbf = binary_tree_balance(n->right);

	if (rbf > 0)
	{
		c_root = binary_tree_rotate_right(n->right);
		n->right = c_root;
		c_root->parent = n;
		r_root = binary_tree_rotate_left(n);
	}
	else
	{
		r_root = binary_tree_rotate_left(n);
	}

	return (r_root);
}

/**
 * del_rotate_right - right rotates a subtree to balance an AVL tree.
 * @n: pointer to the root node of the subtree.
 * Return: the new root node of the rotated subtree.
 */

avl_t *del_rotate_right(avl_t *n)
{
	avl_t *r_root = NULL;
	avl_t *c_root = NULL;
	int lbf;

	if (n == NULL)
		return (NULL);

	lbf = binary_tree_balance(n->left);

	if (lbf < 0)
	{
		c_root = binary_tree_rotate_left(n->left);
		n->left = c_root;
		c_root->parent = n;
		r_root = binary_tree_rotate_right(n);
	}
	else
	{
		r_root = binary_tree_rotate_right(n);
	}

	return (r_root);
}

/**
 * del_avl_balance - balances an AVL tree after a deletion.
 * @tree: double pointer to the root node of the tree.
 * @node: pointer to the root node of the first affected subtree.
 */

void del_avl_balance(avl_t **tree, avl_t *node)
{
	avl_t *r_root = NULL, *p = NULL;
	int bf;

	while (node)
	{
		p = node->parent;
		bf = binary_tree_balance(node);

		if (abs(bf) <= 1)
		{
			node = p;
			continue;
		}

		if (bf > 1)
			r_root = del_rotate_right(node);
		else
			r_root = del_rotate_left(node);

		r_root->parent = p;

		if (p)
		{
			if (node == p->left)
				p->left = r_root;
			else
				p->right = r_root;
		}
		else
			*tree = r_root;

		node = p;
	}
}

/**
 * avl_remove - Removes a node from an AVL tree.
 * @root: pointer to the root node of the tree for removing a node.
 * @value: value to remove in the tree.
 * Return: a pointer to the root node of the updated BST.
 */

avl_t *avl_remove(avl_t *root, int value)
{
	avl_t *node, *succ, *aff_sub;

	if (root == NULL)
		return (NULL);

	node = root;
	while (node && node->n != value)
		if (node->n > value)
			node = node->left;
		else
			node = node->right;
	if (node == NULL)
		return (NULL);

	aff_sub = node->parent;
	if (node->left == NULL)
		shift_nodes(&root, node, node->right);
	else if (node->right == NULL)
		shift_nodes(&root, node, node->left);
	else
	{
		succ = node->right;
		while (succ->left)
			succ = succ->left;

		if (succ->parent != node)
		{
			aff_sub = succ->parent;
			shift_nodes(&root, succ, succ->right);
			succ->right = node->right;
			succ->right->parent = succ;
		}
		shift_nodes(&root, node, succ);
		succ->left = node->left;
		succ->left->parent = succ;
	}

	del_avl_balance(&root, aff_sub);
	free(node);
	return (root);
}
