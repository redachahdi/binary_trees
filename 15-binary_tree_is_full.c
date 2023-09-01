#include "binary_trees.h"
#include <stdlib.h>
#include <stdio.h>
/**
 * binary_tree_is_leaf - is the check node leaf or not
 *
 * @node: is the node to check
 *
 * Return: 1 if node if leaf 0 if not
 */
int r_binary_tree_is_leaf_r(const binary_tree_t *node)
{
	if (node == NULL)
		return (0);
	else if (node->left == NULL && node->right == NULL)
		return (1);
	return (0);
}

/**
 * binary_tree_is_full -  is the checks if a binary tree 
 *
 * @tree: is the node to a tree
 *
 * Return: is the 1 if full 0 otherwise
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	int left;
	int right;

	if (tree == NULL)
		return (0);
	if (r_binary_tree_is_leaf_r(tree) != 0)
		return (1);
	left = binary_tree_is_full(tree->left);
	right = binary_tree_is_full(tree->right);
	if (left == 0 || right == 0)
		return (0);
	return (1);
}
