#include "binary_trees.h"
#include <stdlib.h>
#include <stdio.h>
/**
 * binary_tree_nodes - is the Counts the nodes with at least 1
 *
 * @tree: A pointer to the root node of the tree to count the number of nodes.
 *
 * Return: If tree is NULL, the function must return 0, else return node count.
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t r_nodes = 0;

	if (tree)
	{
		r_nodes += (tree->left || tree->right) ? 1 : 0;
		r_nodes += binary_tree_nodes(tree->left);
		r_nodes += binary_tree_nodes(tree->right);
	}
	return (r_nodes);
}
