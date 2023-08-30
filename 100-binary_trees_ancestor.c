#include "binary_trees.h"

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes.
 * @first: pointer to the first node.
 * @second: pointer to the second node.
 * Return: A pointer to the lowest common ancestor node,
 *	or NULL if no common ancestor was found.
 */

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	const binary_tree_t *anc1, *anc2;

	for (anc1 = first; anc1; anc1 = anc1->parent)
		for (anc2 = second; anc2; anc2 = anc2->parent)
			if (anc1 == anc2)
				return ((binary_tree_t *)anc1);
	return (NULL);
}
