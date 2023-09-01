#include "binary_trees.h"
#include <stdlib.h>
#include <stdio.h>
/**
 * binary_tree_size - is the measures the size of
 *
 * @tree: is the pointer to the root node of the t
 *
 * Return: is the 0 if tree is NULL el
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t r_h_left, r_h_right;

	if (tree == NULL)
		return (0);
	r_h_left = binary_tree_size(tree->left);
	r_h_right = binary_tree_size(tree->right);

	return (r_h_right + 1 + r_h_left);

}
