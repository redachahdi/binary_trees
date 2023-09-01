#include "binary_trees.h"
#include <stdlib.h>
#include <stdio.h>
/**
 * binary_tree_height - is the measures the height of a binary tree.
 *
 * @tree:is the  pointer to the root node of 
 *
 *
 * Return: is the If tree is NULL, your function must return
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t _l = 0, _r = 0;

		_l = tree->left ? 1 + binary_tree_height(tree->left) : 0;
		_r = tree->right ? 1 + binary_tree_height(tree->right) : 0;
		return ((_l > _r) ? _l : _r);
	}
	return (0);
}
